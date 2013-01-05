#ifndef mani_internal_h__
#define mani_internal_h__

extern "C" 
{
#include "lua.h"
#include "lualib.h"
#include "lauxlib.h"
}

#if !defined(PLATFORM_WIN_THREADS) && !defined(PLATFORM_POSIX_THREADS)
#	ifdef _MSC_VER
#		define PLATFORM_WIN_THREADS 1
#	else 
#		define PLATFORM_POSIX_THREADS 1
#	endif
#endif

#include <cassert>
#include <cstdlib>

namespace mani
{
	namespace details
	{
		template<typename AllocationPolicy> 
		class mani_object : protected AllocationPolicy
		{
		protected:
			mani_object() {}
			~mani_object() {}
		public:
			static void* operator new( size_t sz ) { return allocate(sz); }
			static void* operator new [] ( size_t sz ) { return allocate(sz); }

			static void* operator new( size_t, void* p ) { return p; }

			static void	 operator delete( void* p, size_t sz ) { deallocate(p, sz); }
			static void  operator delete[] ( void* p, size_t sz ) { deallocate(p, sz); }
		};
	}
}

#endif // mani_internal_h__
