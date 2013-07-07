//  ==================================================================================
//
//  File:        Upvalue.h
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
#ifndef mani_details_functional_Upvalue_h__
#define mani_details_functional_Upvalue_h__

namespace mani
{
	namespace details
	{
		namespace functional_utils
		{
			namespace __private
			{
				template< typename T >
				void upvalue_reader( lua_State* l, T& value, int idx )
				{
					using namespace mani;
					value = get_from_stack<T>( l, lua_upvalueindex(idx) );
				}

				template< typename TupleType, int idx, int left_elems >
				struct read_upvalue;

				template< typename TupleType, int idx>
				struct read_upvalue< TupleType, idx, 0 >
				{
					static void run( lua_State* l, TupleType& tuple, int& lua_idx )
					{}
				};

				template< typename TupleType, int idx, int left_elems>
				struct read_upvalue
				{
					static void run( lua_State* l, TupleType& tuple, int& lua_idx )
					{
						upvalue_reader( l, mani::details::type_utils::Field<idx>( tuple ), lua_idx );
						++lua_idx;
						read_upvalue< TupleType, idx + 1, left_elems - idx - 1>::run( l, tuple, lua_idx );
					}
				};
			}

			template< int length, int tfrom, typename TupleType >
			void    read_upvalue( lua_State* l, TupleType& tuple, int from_index = 2 )
			{
				int idx = from_index;
				__private::read_upvalue<TupleType, tfrom, length>::run( l, tuple, idx );
			}
		}
	}
}

#endif // mani_details_functional_Upvalue_h__