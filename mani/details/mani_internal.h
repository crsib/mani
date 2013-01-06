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

#ifndef MANI_NO_ATOMICS
#	ifdef PLATFORM_WIN_THREADS
#		include <Windows.h>
#		define  MANI_ATOMIC_INC( ptr ) InterlockedIncrement( ptr )
#		define  MANI_ATOMIC_DEC( ptr ) InterlockedDecrement( ptr )
#	elif defined(PLATFORM_POSIX_THREADS)
#		define  MANI_ATOMIC_INC( ptr ) __sync_add_and_fetch ( ptr, 1 )
#		define  MANI_ATOMIC_DEC( ptr ) __sync_sub_and_fetch ( ptr, 1 )
#	endif
#else
template<typename Type>
inline Type __mani_inc( Type volatile* ptr ) { *ptr += 1; return *ptr; }

template<typename Type>
inline Type __mani_dec( Type volatile* ptr ) { *ptr -= 1; return *ptr; }

#	define  MANI_ATOMIC_INC( ptr ) __mani_inc( ptr )
#	define  MANI_ATOMIC_DEC( ptr ) __mani_dec( ptr )
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
