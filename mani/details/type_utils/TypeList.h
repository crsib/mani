//  ==================================================================================
//
//  File:        TypeList.h
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

// The code is mostly a copy of Loki TypeList from Andrei Alexandrescu's Loki library

#ifndef mani_details_type_utils_TypeList_h__
#define mani_details_type_utils_TypeList_h__

#include "mani/details/type_utils/Base.h"

namespace mani
{
	namespace details
	{
		namespace type_utils
		{
			template< typename First, typename Second >
			struct TypeList
			{
				typedef First  head_t;
				typedef Second tail_t;
			};

			template< 
				typename T1 = NullType, typename T2 = NullType, typename T3 = NullType, typename T4 = NullType,
				typename T5 = NullType, typename T6 = NullType, typename T7 = NullType, typename T8 = NullType,
				typename T9 = NullType, typename T10 = NullType, typename T11 = NullType, typename T12 = NullType,
				typename T13 = NullType, typename T14 = NullType, typename T15 = NullType, typename T16 = NullType,
				typename T17 = NullType, typename T18 = NullType, typename T19 = NullType, typename T20 = NullType
			>
			struct Vector
			{
			private:
				typedef typename Vector< 
					T2, T3, T4, T5, T6, T7, T8, T9, T10, T11,
					T12, T13, T14, T15, T16, T17, T18, T19, T20
				>::result_t tail_type_t;
			public:
				typedef TypeList< T1, tail_type_t > result_t;
			};

			template<>
			struct Vector<>
			{
				typedef NullType result_t;
			};

			template<typename TList>
			struct Length;

			template<>
			struct Length<NullType>
			{
				enum { result = 0 };
			};

			template< >
			struct Length< TypeList<NullType,NullType> >
			{
				enum { result = 0 };
			};

			template< typename T1, typename T2 >
			struct Length< TypeList<T1,T2> >
			{
				enum { result = 1 + Length<T2>::result };
			};

			template< typename TList, int idx>
			struct TypeAt;

			template< typename T1, typename T2 >
			struct TypeAt< TypeList<T1, T2>, 0 >
			{
				typedef T1 result_t;
			};

			template< typename T1, typename T2, int idx >
			struct TypeAt< TypeList<T1,T2>, idx >
			{
				typedef typename TypeAt< T2, idx - 1>::result_t result_t;
			};

			template <class TList, class T> 
			struct IndexOf;

			template <class T>
			struct IndexOf<NullType, T>
			{
				enum { result = -1 };
			};

			template <class T, class Tail>
			struct IndexOf<TypeList<T, Tail>, T>
			{
				enum { result = 0 };
			};

			template <class Head, class Tail, class T>
			struct IndexOf<TypeList<Head, Tail>, T>
			{
			private:
				enum { temp = IndexOf<Tail, T>::result };
			public:
				enum { result = (temp == -1 ? -1 : 1 + temp) };
			};
		}
	}
}
#endif // mani_details_type_utils_TypeList_h__
