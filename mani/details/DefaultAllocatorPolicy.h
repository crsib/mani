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
			void*     allocate( size_t size ) {	return ::malloc( size ); }
			void*     reallocate( void* ptr, size_t old_size, size_t new_size ) { (void) old_size; return ::realloc( ptr, new_size ); }
			void      deallocate( void* ptr, size_t size ) { (void) size; ::free( ptr ); }
		};
	}
}

#endif // DefaultAllocatorPolicy_h__
