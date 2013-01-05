#ifndef mani_thread_local_h__
#define mani_thread_local_h__

#include "mani/details/mani_internal.h"

#if defined(PLATFORM_WIN_THREADS)
#	include <Windows.h>
#elif defined(PLATFORM_POSIX_THREADS)
#	include <pthread.h>
#else
#	error "Unsupported threading platform"
#endif

namespace mani
{
	namespace details
	{
		class tl_state
		{
		public:
			tl_state();
			~tl_state();

			lua_State*  get() const;
			void        set( lua_State* state );
		private:
#if defined(PLATFORM_WIN_THREADS)
			DWORD       m_Index;
#elif defined(PLATFORM_POSIX_THREADS)
			pthread_key_t m_Key;
#endif
		};

#if defined(PLATFORM_WIN_THREADS)
		tl_state::tl_state()
			: m_Index( TlsAlloc() )
		{}

		tl_state::~tl_state()
		{ TlsFree( m_Index );	}

		lua_State* tl_state::get() const
		{ return reinterpret_cast<lua_State*>( TlsGetValue( m_Index ) ); }

		void tl_state::set( lua_State* state )
		{ TlsSetValue( m_Index, state ); }
#elif defined(PLATFORM_POSIX_THREADS)
		tl_state::tl_state()
		{ pthread_key_create( &m_Key, NULL ); }

		tl_state::~tl_state()
		{ pthread_key_delete( m_Key ); }

		lua_State* tl_state::get() const
		{ return reinterpret_cast<lua_State*>( pthread_getspecific( m_Key ) ); }

		void tl_state::set( lua_State* state )
		{ pthread_setspecific( m_Key, state ); }
#endif
	}
}

#endif // thread_local_h__
