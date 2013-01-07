//  ==================================================================================
//
//  File:        DefaultAllocatorPolicy.h
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
#ifndef DefaultAllocatorPolicy_h__
#define DefaultAllocatorPolicy_h__

#include "mani/details/mani_internal.h"

namespace mani
{
	namespace details
	{
		class DefaultAllocationPolicy
		{
		public:
			static void*     allocate( size_t size ) {	return ::malloc( size ); }
			static void*     reallocate( void* ptr, size_t old_size, size_t new_size ) { (void) old_size; return ::realloc( ptr, new_size ); }
			static void      deallocate( void* ptr, size_t size ) { (void) size; ::free( ptr ); }
		};
	}
}

#endif // DefaultAllocatorPolicy_h__
