//  ==================================================================================
//
//  File:        BinderProxy.h
//  Description:
//  Comments:
//  Author:      Dmitry Vedenko
//  E-mail:      vedenko@gmail.com
//
//  The source code is licensed under the BSD 2-clause license. 
//  Redistribution and use in source and binary forms, with or without modification, 
//  are permitted provided that the requirements in the LICENSE file provided are met. 
//
//  ==================================================================================

#ifndef mani_details_functional_BinderProxy_h__
#define mani_details_functional_BinderProxy_h__

#include "mani/details/functional_utils/Parameter.h"
#include "mani/details/functional_utils/Upvalue.h"
#include "mani/details/functional_utils/DeduceSignature.h"

namespace mani
{
	namespace details
	{
		namespace functional_utils
		{
			namespace __private
			{
				template<typename TSignature, int upvalues>
				struct BinderProxy
				{
					template<typename T, typename Tuple, typename FnPtr>
					struct rv_proxy_t;

					template<typename Tuple, typename FnPtr>
					struct rv_proxy_t<void, Tuple, FnPtr >
					{
						static int push_result( lua_State* state, typename TSignature::class_t* __this, FnPtr fn, Tuple& params)
						{
							apply( TSignature(), __this, fn, params );
							return 0;	
						}
					};

					template<typename T, typename Tuple, typename FnPtr>
					struct rv_proxy_t
					{
						static int push_result( lua_State* state, typename TSignature::class_t* __this, FnPtr fn, Tuple& params )
						{
							using namespace mani;
							push_to_stack( state, apply( TSignature(), __this, fn, params ) ); 
							return 1;
						}
					};

					static int proxy( lua_State* state, mani::details::type_utils::true_type ) // For class methods
					{
						using namespace mani::details::type_utils;
						using namespace mani::details::functional_utils;

						if( Length< typename TSignature::parameters_t >::result <= lua_gettop( state) )
						{
							lua_pushstring( state, "Invalid argument count. Binder does not support the default nil." );
							lua_error( state );
							return 0;
						}

						typename TSignature::pointer_t fn = reinterpret_cast< mani::details::type_utils::MemberPointerWrapper< typename TSignature::pointer_t >* >( lua_touserdata( state, lua_upvalueindex(1) ) )->pointer;

						if(!fn)
						{
							lua_pushstring( state, "Failed to get the pointer to the method");
							lua_error( state );
							return 0;
						}

						typename TSignature::class_t* __this = get_from_stack<typename TSignature::class_t*>( state, 1 );

						Tuple< typename TSignature::parameters_t > params;
						mani::details::functional_utils::from_stack< Length< typename TSignature::parameters_t >::result, upvalues >( state, params, 1 );
						int count = rv_proxy_t< typename TSignature::return_value_t, Tuple< typename TSignature::parameters_t >, typename TSignature::pointer_t>::push_result( state, __this, fn, params );
						count += mani::details::functional_utils::to_stack< Length< typename TSignature::parameters_t >::result >( state, params );

						return count;
					}

					static int proxy( lua_State* state, mani::details::type_utils::false_type ) // For free functions and static methods
					{
						using namespace mani::details::type_utils;
						using namespace mani::details::functional_utils;
						 
						if( (Length< typename TSignature::parameters_t >::result - upvalues) <  lua_gettop( state ) ) 
						{
							lua_pushstring( state, "Invalid argument count. Binder does not support the default nil." );
							lua_error( state );
							return 0;
						}

						typename TSignature::pointer_t fn = reinterpret_cast<typename TSignature::pointer_t>( lua_touserdata( state, lua_upvalueindex(1) ) );

						if(!fn)
						{
							lua_pushstring( state, "Failed to get the pointer to the function");
							lua_error( state );
							return 0;
						}

						Tuple< typename TSignature::parameters_t > params;

						// allow the compiler to optimize this branch out when there are no upvalues
						if( upvalues > 0 )
							mani::details::functional_utils::read_upvalue< upvalues, 0 >( state, params );

						mani::details::functional_utils::from_stack< Length< typename TSignature::parameters_t >::result - upvalues, upvalues >( state, params );
						int count = rv_proxy_t< typename TSignature::return_value_t, Tuple< typename TSignature::parameters_t >, typename TSignature::pointer_t>::push_result( state, NULL, fn, params );
						assert( lua_gettop( state ) >= count );
						count += mani::details::functional_utils::to_stack< Length< typename TSignature::parameters_t >::result >( state, params );
						assert( lua_gettop( state ) >= count );
						return count; 
					}

					static int call_proxy( lua_State* state )
					{
						typename mani::details::type_utils::Select< TSignature::is_method, mani::details::type_utils::true_type, mani::details::type_utils::false_type>::result_t type;
						return proxy( state, type );
					}

					lua_CFunction getProxy() { return call_proxy; }
				};
			}

			template<int upvalues, typename TSignature>
			lua_CFunction binder_proxy( TSignature  )
			{
				return __private::BinderProxy<TSignature, upvalues>::call_proxy;
			}
		}
	}
}

#endif // mani_details_functional_BinderProxy_h__
