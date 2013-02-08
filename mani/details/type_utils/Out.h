//  ==================================================================================
//
//  File:        Out.h
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

#ifndef mani_details_type_utils_Out_h__
#define mani_details_type_utils_Out_h__

#include "mani/details/type_utils/Traits.h"

namespace mani
{
	template<typename T>
	struct out
	{
		typedef T type;
		typedef typename details::type_utils::Select< details::type_utils::Traits<T>::is_reference, 
			T, T&> reference;

		reference value;

		out( reference __val )
			: value( __val )
		{}

	private:
		out( const out& );
		out& operator = ( const out& );
	};
}

#endif // mani_details_type_utils_Out_h__
