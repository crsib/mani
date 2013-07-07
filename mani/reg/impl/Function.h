//  ==================================================================================
//
//  File:        Function.h
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

#ifndef mani_reg_impl_Function_h__
#define mani_reg_impl_Function_h__

#include "mani/details/functional_utils/BinderProxy.h"

namespace mani
{
	namespace reg
	{
		namespace __private
		{
			template<typename LuaInterpType, typename StringType>
			struct FunctionImpl
			{
				FunctionImpl( const LuaInterpType& lua, const StringType& name, int upvalues, lua_CFunction fn, void* fn_ptr )
					: Lua( lua ), UpvaluesCount( upvalues ), PassedUpvalues( 0 ), Function( fn )
				{
					lua_State* l = Lua.getVirtualMachine();
					StackTop = lua_gettop( l );
					impl::check_stack_top_table( l );

					lua_getmetatable( l, -1 ); //Both global and module should have the meta-table
					// If not, we still have a table on top

					using namespace mani;
					push_to_stack( l,  name );

					if( fn_ptr )
					{
						++UpvaluesCount;
						++PassedUpvalues;
						lua_pushlightuserdata( l, fn_ptr );
					}
				}

				~FunctionImpl() 
				{
					lua_State* l = Lua.getVirtualMachine();
					lua_pushcclosure( l, Function, PassedUpvalues );
					lua_settable( l, -3 );
					lua_settop( l, StackTop ); 
					printf( "\t~FunctionImpl\n" );
				}

				template<typename T> 
				FunctionImpl& upvalue( const T& _val )
				{
					printf( "Upvalue\n" );
					using namespace mani;
					if( PassedUpvalues < UpvaluesCount )
					{
						++PassedUpvalues;
						push_to_stack( Lua.getVirtualMachine(), _val );
					}

					return *this;
				}

				const LuaInterpType&   Lua;
				int              UpvaluesCount;
				int              PassedUpvalues;
				int              StackTop;
				lua_CFunction    Function;

			};
		}

		template<int upvalues, typename LuaInterpType, typename StringType, typename F>
		__private::FunctionImpl<LuaInterpType, StringType>  function( const LuaInterpType& lua, const StringType& function_name, F fn )
		{
			lua_CFunction lua_fn = mani::details::functional_utils::binder_proxy<upvalues>( mani::details::functional_utils::deduce_signature( fn ) );
			return __private::FunctionImpl<LuaInterpType, StringType>( lua, function_name, upvalues, lua_fn, reinterpret_cast<void*>( fn ) );
		}

		template< typename LuaInterpType, typename StringType, typename F>
		__private::FunctionImpl<LuaInterpType, StringType>  function( const LuaInterpType& lua, const StringType& function_name, F fn )
		{
			lua_CFunction lua_fn = mani::details::functional_utils::binder_proxy<0>( mani::details::functional_utils::deduce_signature( fn ) );
			return __private::FunctionImpl<LuaInterpType, StringType>( lua, function_name, 0, lua_fn, reinterpret_cast<void*>( fn ) );
		}

		template<int upvalues, typename LuaInterpType, typename StringType>
		__private::FunctionImpl<LuaInterpType, StringType>  cfunction( const LuaInterpType& lua, const StringType& function_name, lua_CFunction fn )
		{
			return __private::FunctionImpl<LuaInterpType, StringType>( lua, function_name, upvalues, fn, NULL );
		}

		template< typename LuaInterpType, typename StringType>
		__private::FunctionImpl<LuaInterpType, StringType>  cfunction( const LuaInterpType& lua, const StringType& function_name, lua_CFunction fn )
		{
			return __private::FunctionImpl<LuaInterpType, StringType>( lua, function_name, 0, fn, NULL );
		}
	}
}

#endif // mani_reg_impl_Function_h__
