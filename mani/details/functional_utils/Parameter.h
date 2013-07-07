//  ==================================================================================
//
//  File:        Parameter.h
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

#ifndef mani_details_functional_Parameter_h__
#define mani_details_functional_Parameter_h__

#include "mani/details/type_utils/Out.h"
#include "mani/details/functional_utils/Signature.h"
#include "mani/details/mani_internal.h"

namespace mani
{
	namespace details
	{
		namespace functional_utils
		{
			namespace __private
			{
				template<typename T>
				struct Parameter;

				template<typename T>
				struct Parameter< mani::out<T> >
				{
					enum
					{
						out = 1,
						in  = 0
					};

					static void from_stack( lua_State*, int , mani::out<T>&, int&  )
					{}

					static void to_stack( lua_State* l, mani::out<T>& p, int& count )
					{
						using namespace mani;
						push_to_stack( l, p.value );
						++count;
					}
				};

				template<typename T>
				struct Parameter
				{
					enum
					{
						out = 0,
						in  = 1
					};

					static void from_stack( lua_State* l, int idx, typename mani::details::type_utils::Traits<T>::referred_type_t _val, int& next_idx )
					{
						using namespace mani;
						_val = get_from_stack<T>( l, idx );
						++next_idx;
					}

					static void to_stack( lua_State* l, const T&, int&  )
					{}
				};

				template<typename T>
				void    value_from_stack( lua_State* l, T value, int& idx )
				{ Parameter<T>::from_stack( l, idx, value, idx );	}

				template<typename T>
				void    value_to_stack( lua_State* l, T value, int& count )
				{ Parameter<T>::to_stack( l, value, count ); }

				template< typename TupleType, int idx, int left_elems >
				struct from_stack;

				template< typename TupleType, int idx>
				struct from_stack< TupleType, idx, 0 >
				{
					static void run( lua_State* l, TupleType& tuple, int& lua_idx )
					{}
				};

				template< typename TupleType, int idx, int left_elems>
				struct from_stack
				{
					static void run( lua_State* l, TupleType& tuple, int& lua_idx )
					{
						value_from_stack( l, mani::details::type_utils::Field<idx>( tuple ), lua_idx );

						from_stack< TupleType, idx + 1, left_elems - idx - 1>::run( l, tuple, lua_idx );
					}
				};

				template< typename TupleType, int idx, int left_elems >
				struct to_stack;

				template< typename TupleType, int idx>
				struct to_stack< TupleType, idx, 0 >
				{
					static void run( lua_State* l, const TupleType& tuple, int& count )
					{}
				};

				template< typename TupleType, int idx, int left_elems>
				struct to_stack
				{
					static void run( lua_State* l, const TupleType& tuple, int& count )
					{
						value_to_stack( l, mani::details::type_utils::Field<idx>( tuple ), count );

						to_stack< TupleType, idx + 1, left_elems - idx - 1>::run( l, tuple, count );
					}
				};
			}

			template< int length, int tfrom, typename TupleType >
			void    from_stack( lua_State* l, TupleType& tuple, int from_index = 1 )
			{
				int idx = from_index;
				__private::from_stack<TupleType, tfrom, length>::run( l, tuple, idx );
			}

			template< int length, typename TupleType >
			int    to_stack( lua_State* l, const TupleType& tuple )
			{
				int count = 0;
				__private::to_stack<TupleType, 0, length>::run( l, tuple, count );
				return count;
			}
		}
	}
}

#endif // mani_details_functional_Parameter_h__
