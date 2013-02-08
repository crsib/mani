//  ==================================================================================
//
//  File:        fake.cpp
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

#include "mani/details/type_utils/Base.h"
#include "mani/details/type_utils/Out.h"
#include "mani/details/type_utils/Traits.h"
#include "mani/details/type_utils/Tuple.h"
#include "mani/details/type_utils/TypeList.h"

#include "mani/details/functional_utils/DeduceSignature.h"
#include "mani/details/functional_utils/Apply.h"

void traits_comp_test()
{
	mani::details::type_utils::Traits<int>::is_arith == 1;
	mani::details::type_utils::Tuple< mani::details::type_utils::Vector< int, float, int >::result_t > tuple1, tuple2;
	mani::details::type_utils::Field<0>(tuple1) = 2;

	tuple2 = tuple1;

	mani::details::type_utils::make_tuple<int>( 10 );

	mani::details::functional_utils::deduce_signature( traits_comp_test );
}
