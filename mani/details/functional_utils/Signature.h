//  ==================================================================================
//
//  File:        Signature.h
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

#ifndef mani_details_functional_Signature_h__
#define mani_details_functional_Signature_h__

#include "mani/details/type_utils/TypeList.h"

namespace mani
{
	namespace details
	{
		namespace functional_utils
		{
			template< typename ReturnValue, typename Sig, typename CallSigPtr, class Class = mani::details::type_utils::NullType >
			struct Signature
			{
				typedef ReturnValue return_value_t;

				typedef typename mani::details::type_utils::Select<
					mani::details::type_utils::IsSameType< mani::details::type_utils::NullType, typename Sig::result_t >::result ,
					mani::details::type_utils::TypeList<mani::details::type_utils::NullType, mani::details::type_utils::NullType>, 
					typename Sig::result_t
				>::result_t         parameters_t;

				typedef Class       class_t;
				typedef CallSigPtr  pointer_t;

				enum
				{
					has_return_value = !mani::details::type_utils::IsSameType< void, return_value_t >::result,
					is_method        = !mani::details::type_utils::IsSameType< mani::details::type_utils::NullType, class_t >::result,
					arg_count        =  mani::details::type_utils::Length< parameters_t >::result
				};
			};
		}
	}
}

#endif // mani_details_functional_Signature_h__
