//  ==================================================================================
//
//  File:        Tuple.h
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

// The code is mostly a copy of Loki Tuple from Andrei Alexandrescu's Loki library

#ifndef mani_details_type_utils_Tuple_h__
#define mani_details_type_utils_Tuple_h__

#include "mani/details/type_utils/TypeList.h"
#include "mani/details/type_utils/Traits.h"

#if defined(_MSC_VER) && _MSC_VER >= 1300
#pragma warning( push ) 
// 'class1' : base-class 'class2' is already a base-class of 'class3'
#pragma warning( disable : 4584 )
#endif // _MSC_VER

namespace mani
{
	namespace details
	{
		namespace type_utils
		{
			namespace internal
			{
				template<class, class> 
				struct ScatterHierarchyTag;

				template <class TList, template <class> class Unit>
				class GenScatterHierarchy;

				template <class T1, class T2, template <class> class Unit>
				class GenScatterHierarchy<TypeList<T1, T2>, Unit>
					: public GenScatterHierarchy<ScatterHierarchyTag<T1, T2>, Unit>
					, public GenScatterHierarchy<T2, Unit>
				{
				public:
					typedef TypeList<T1, T2> TList;
					// Insure that left_base_t is unique and therefore reachable
					typedef GenScatterHierarchy<ScatterHierarchyTag<T1, T2>, Unit> left_base_t;
					typedef GenScatterHierarchy<T2, Unit> right_base_t;
					template <typename T> struct Rebind
					{
						typedef Unit<T> Result;
					};
				};

				// In the middle *unique* class that resolve possible ambiguity
				template <class T1, class T2, template <class> class Unit>
				class GenScatterHierarchy<ScatterHierarchyTag<T1, T2>, Unit> 
					: public GenScatterHierarchy<T1, Unit>
				{
				};

				template <class AtomicType, template <class> class Unit>
				class GenScatterHierarchy : public Unit<AtomicType>
				{
					typedef Unit<AtomicType> left_base_t;
					template <typename T> struct Rebind
					{
						typedef Unit<T> Result;
					};
				};

				template <template <class> class Unit>
				class GenScatterHierarchy<NullType, Unit>
				{
					template <typename T> struct Rebind
					{
						typedef Unit<T> Result;
					};
				};

				template <class T, class H>
				typename H::template Rebind<T>::Result& Field(H& obj)
				{
					return obj;
				}

				template <class T, class H>
				const typename H::template Rebind<T>::Result& Field(const H& obj)
				{
					return obj;
				}

				template <class T>
				struct TupleUnit
				{
					T m_Value;
					operator T&() { return m_Value; }
					operator const T&() const { return m_Value; }
				};

				template <class H, unsigned int i> struct FieldHelper;

				template <class H>
				struct FieldHelper<H, 0>
				{
					typedef typename H::TList::head_t ElementType;
					typedef typename H::template Rebind<ElementType>::Result UnitType;

					enum
					{
						is_tuple = Conversion<UnitType, TupleUnit<ElementType> >::same_type,
						is_const = Traits<H>::is_const
					};

					typedef const typename H::left_base_t ConstLeftBase;

					typedef typename Select<is_const, ConstLeftBase, 
						typename H::left_base_t>::Result LeftBase;

					typedef typename Select<is_tuple, ElementType, 
						UnitType>::Result UnqualifiedResultType;

					typedef typename Select<is_const, const UnqualifiedResultType,
						UnqualifiedResultType>::Result ResultType;

					static ResultType& Do(H& obj)
					{
						LeftBase& leftBase = obj;
						return leftBase;
					}
				};

				template <class H, unsigned int i>
				struct FieldHelper
				{
					typedef typename TypeAt<typename H::TList, i>::Result ElementType;
					typedef typename H::template Rebind<ElementType>::Result UnitType;

					enum
					{
						is_tuple = Conversion<UnitType, TupleUnit<ElementType> >::same_type,
						is_const = Traits<H>::is_const
					};

					typedef const typename H::RightBase ConstRightBase;

					typedef typename Select<is_const, ConstRightBase, 
						typename H::RightBase>::Result RightBase;

					typedef typename Select<is_tuple, ElementType, 
						UnitType>::Result UnqualifiedResultType;

					typedef typename Select<is_const, const UnqualifiedResultType,
						UnqualifiedResultType>::Result ResultType;

					static ResultType& Do(H& obj)
					{
						RightBase& rightBase = obj;
						return FieldHelper<RightBase, i - 1>::Do(rightBase);
					}
				};
			}

			template <int i, class H>
			typename internal::FieldHelper<H, i>::ResultType&
				Field(H& obj)
			{
				return internal::FieldHelper<H, i>::Do(obj);
			}

			template<class TList>
			struct Tuple : public internal::GenScatterHierarchy<TList, internal::TupleUnit>
			{
			};

			template<typename T1>
			Tuple<typename mani::details::type_utils::template Vector< T1 >::result_t>
				make_tuple( typename Traits<T1>::parameter_type_t p1 )
			{
				Tuple<typename mani::details::type_utils::template Vector< T1 >::result_t> tuple;
				Field<0>( tuple ) = p1;
				return tuple;
			}

			template<typename T1, typename T2>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2 >::result_t>
				make_tuple( typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2 )
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				return tuple;
			}

			template<typename T1, typename T2, typename T3>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3 >::result_t>
				make_tuple( typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3 )
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;
				return tuple;
			}

			template<typename T1, typename T2, typename T3, typename T4>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4 >::result_t>
				make_tuple( 
				typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3,
				typename Traits<T4>::parameter_type_t p4
				)
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;	Field<3>( tuple ) = p4;
				return tuple;
			}

			template<typename T1, typename T2, typename T3, typename T4, typename T5>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5 >::result_t>
				make_tuple( 
				typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3,
				typename Traits<T4>::parameter_type_t p4, typename Traits<T5>::parameter_type_t p5
				)
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;	Field<3>( tuple ) = p4;
				Field<4>( tuple ) = p5;
				return tuple;
			}

			template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6 >::result_t>
				make_tuple( 
				typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3,
				typename Traits<T4>::parameter_type_t p4, typename Traits<T5>::parameter_type_t p5, typename Traits<T6>::parameter_type_t p6
				)
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;	Field<3>( tuple ) = p4;
				Field<4>( tuple ) = p5;	Field<5>( tuple ) = p6;
				return tuple;
			}

			template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6, T7 >::result_t>
				make_tuple( 
				typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3,
				typename Traits<T4>::parameter_type_t p4, typename Traits<T5>::parameter_type_t p5, typename Traits<T6>::parameter_type_t p6,
				typename Traits<T7>::parameter_type_t p7
				)
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6, T7 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;	Field<3>( tuple ) = p4;
				Field<4>( tuple ) = p5;	Field<5>( tuple ) = p6;
				Field<6>( tuple ) = p7;
				return tuple;
			}

			template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6, T7, T8 >::result_t>
				make_tuple( 
				typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3,
				typename Traits<T4>::parameter_type_t p4, typename Traits<T5>::parameter_type_t p5, typename Traits<T6>::parameter_type_t p6,
				typename Traits<T7>::parameter_type_t p7, typename Traits<T8>::parameter_type_t p8
				)
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6, T7, T8 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;	Field<3>( tuple ) = p4;
				Field<4>( tuple ) = p5;	Field<5>( tuple ) = p6;
				Field<6>( tuple ) = p7; Field<7>( tuple ) = p8;
				return tuple;
			}

			template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
			Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9 >::result_t>
				make_tuple( 
				typename Traits<T1>::parameter_type_t p1, typename Traits<T2>::parameter_type_t p2, typename Traits<T3>::parameter_type_t p3,
				typename Traits<T4>::parameter_type_t p4, typename Traits<T5>::parameter_type_t p5, typename Traits<T6>::parameter_type_t p6,
				typename Traits<T7>::parameter_type_t p7, typename Traits<T8>::parameter_type_t p8, typename Traits<T9>::parameter_type_t p9
				)
			{
				Tuple<typename mani::details::type_utils::template Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9 >::result_t> tuple;
				Field<0>( tuple ) = p1;	Field<1>( tuple ) = p2;
				Field<2>( tuple ) = p3;	Field<3>( tuple ) = p4;
				Field<4>( tuple ) = p5;	Field<5>( tuple ) = p6;
				Field<6>( tuple ) = p7; Field<7>( tuple ) = p8;
				Field<8>( tuple ) = p9;
				return tuple;
			}
		}
	}
}

#if defined(_MSC_VER) && _MSC_VER >= 1300
#pragma warning( pop ) 
#endif

#endif // mani_details_type_utils_Tuple_h__