//  ==================================================================================
//
//  File:        DeduceSignature.h
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

#ifndef mani_details_functional_DeduceSignature_h__
#define mani_details_functional_DeduceSignature_h__

#include "mani/details/functional_utils/Signature.h"

namespace mani
{
	namespace details
	{
		namespace functional_utils
		{
			template< typename R >
			Signature< R, mani::details::type_utils::Vector<>, R (*)()  >
				deduce_signature( R (*)() ) 
			{ return Signature< R, mani::details::type_utils::Vector<>, R (*)() >(); }

			template< typename R, typename T1 >
			Signature< R, mani::details::type_utils::Vector< T1 >, R (*)(T1) >
				deduce_signature( R (*)(T1) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1 >, R (*)(T1) >(); }

			template< typename R, typename T1, typename T2 >
			Signature< R, mani::details::type_utils::Vector< T1, T2 >, R (*)(T1, T2) >
				deduce_signature( R (*)(T1, T2) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2 >, R (*)(T1, T2) >(); }

			template< typename R, typename T1, typename T2, typename T3 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3 >, R (*)(T1, T2, T3) >
				deduce_signature( R (*)(T1, T2, T3) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3 >, R (*)(T1, T2, T3) >(); }

			template< typename R, typename T1, typename T2, typename T3, typename T4 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4 >, R (*)(T1, T2, T3, T4) >
				deduce_signature( R (*)(T1, T2, T3, T4) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4 >, R (*)(T1, T2, T3, T4) >(); }

			template< typename R, typename T1, typename T2, typename T3, typename T4, typename T5 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5 >, R (*)(T1, T2, T3, T4, T5) >
				deduce_signature( R (*)(T1, T2, T3, T4, T5) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5 >, R (*)(T1, T2, T3, T4, T5) >(); }

			template< typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6 >, R (*)(T1, T2, T3, T4, T5, T6) >
				deduce_signature( R (*)(T1, T2, T3, T4, T5, T6) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6 >, R (*)(T1, T2, T3, T4, T5, T6) >(); }

			template< 
				typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7 >, R (*)(T1, T2, T3, T4, T5, T6, T7) >
				deduce_signature( R (*)(T1, T2, T3, T4, T5, T6, T7) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7 >, R (*)(T1, T2, T3, T4, T5, T6, T7) >(); }

			template< 
				typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8) >
			deduce_signature( R (*)(T1, T2, T3, T4, T5, T6, T7, T8) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8) >(); }

			template< 
				typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9) >
			deduce_signature( R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9) >(); }

			template< 
				typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9, typename T10
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) >
			deduce_signature( R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) >(); }

			template< 
				typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9, typename T10, typename T11
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) >
			deduce_signature( R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) >(); }

			template< 
				typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9, typename T10, typename T11, typename T12
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) >
			deduce_signature( R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12 >, R (*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) >(); }

			// Methods
			namespace __private
			{
				template<typename T> struct remove_pointer { typedef T result_t; };
				template<typename T> struct remove_pointer<T*> { typedef T result_t; };
			}

			template< typename Class, typename R >
			Signature< R, mani::details::type_utils::Vector<>, R (Class::*)(), Class >
				deduce_signature( R (Class::*)() ) 
			{ return Signature< R, mani::details::type_utils::Vector<>, R (Class::*)(), Class >(); }

			template< typename Class, typename R, typename T1 >
			Signature< R, mani::details::type_utils::Vector< T1 >, R (Class::*)(T1), Class >
				deduce_signature( R (Class::*)(T1) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1 >, R (Class::*)(T1), Class >(); }

			template< typename Class, typename R, typename T1, typename T2 >
			Signature< R, mani::details::type_utils::Vector< T1, T2 >, R (Class::*)(T1, T2), Class >
				deduce_signature( R (Class::*)(T1, T2) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2 >, R (Class::*)(T1, T2), Class >(); }

			template< typename Class, typename R, typename T1, typename T2, typename T3 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3 >, R (Class::*)(T1, T2, T3), Class >
				deduce_signature( R (Class::*)(T1, T2, T3) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3 >, R (Class::*)(T1, T2, T3), Class >(); }

			template< typename Class, typename R, typename T1, typename T2, typename T3, typename T4 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4 >, R (Class::*)(T1, T2, T3, T4), Class >
				deduce_signature( R (Class::*)(T1, T2, T3, T4) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4 >, R (Class::*)(T1, T2, T3, T4) >(); }

			template< typename Class, typename R, typename T1, typename T2, typename T3, typename T4, typename T5 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5 >, R (Class::*)(T1, T2, T3, T4, T5), Class >
				deduce_signature( R (Class::*)(T1, T2, T3, T4, T5) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5 >, R (Class::*)(T1, T2, T3, T4, T5), Class >(); }

			template< typename Class, typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6 >
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6 >, R (Class::*)(T1, T2, T3, T4, T5, T6), Class >
				deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6 >, R (Class::*)(T1, T2, T3, T4, T5, T6), Class >(); }

			template< 
				typename Class, typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7), Class >
			deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6, T7) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7), Class >(); }

			template< 
				typename Class, typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8), Class >
			deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8), Class >(); }

			template< 
				typename Class, typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9), Class >
			deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9), Class >(); }

			template< 
				typename Class, typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9, typename T10
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10), Class >
			deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10), Class >(); }

			template< 
				typename Class, typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9, typename T10, typename T11
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11), Class >
			deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11), Class >(); }

			template< 
				typename Class, typename R, 
				typename T1, typename T2, typename T3, typename T4, typename T5, typename T6,
				typename T7, typename T8, typename T9, typename T10, typename T11, typename T12
			>
			Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12), Class >
			deduce_signature( R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12) ) 
			{ return Signature< R, mani::details::type_utils::Vector< T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12 >, R (Class::*)(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, T11, T12), Class >(); }
		}
	}
}

#endif // mani_details_functional_DeduceSignature_h__
