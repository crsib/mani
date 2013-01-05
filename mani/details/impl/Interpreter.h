#ifndef mani_impl_Interpreter_h__
#define mani_impl_Interpreter_h__

#include "mani/Interpreter.h"

namespace mani
{
	template<typename AllocationPolicy>
	InterpreterBase<AllocationPolicy>::InterpreterBase()
		: m_OwnsState( true )
	{
		m_LuaVM = lua_newstate( InterpreterBase<AllocationPolicy>::lua_alloc, this );
		m_ThreadSpecificStates.set( m_LuaVM );
	}

	template<typename AllocationPolicy>
	InterpreterBase<AllocationPolicy>::InterpreterBase( lua_State* lua )
		: m_LuaVM( lua ), m_OwnsState( false ) { m_ThreadSpecificStates.set( m_LuaVM ); }

	template<typename AllocationPolicy>
	InterpreterBase<AllocationPolicy>::~InterpreterBase()
	{
		if(m_OwnsState)
			lua_close( m_LuaVM );
	}

	template<typename AllocationPolicy>
	void* InterpreterBase<AllocationPolicy>::lua_alloc( void *ud, void *ptr, size_t osize, size_t nsize )
	{
		InterpreterBase<AllocationPolicy>* interpreter = reinterpret_cast<InterpreterBase< AllocationPolicy >* >(ud);

		if( !nsize )
			interpreter->deallocate( ptr, osize );
		else
			return interpreter->reallocate( ptr, osize, nsize );

		return NULL;
	}


	template<typename AllocationPolicy>
	void InterpreterBase<AllocationPolicy>::openStandardLibraries( unsigned libs /*= AllLibs */ )
	{
		static const size_t   __libs_count = 8;
		static const luaL_Reg __lualibs[__libs_count] = {
			{ "", luaopen_base },
			{ LUA_TABLIBNAME, luaopen_table },
			{ LUA_IOLIBNAME, luaopen_io },
			{ LUA_OSLIBNAME, luaopen_os },
			{ LUA_STRLIBNAME, luaopen_string },
			{ LUA_MATHLIBNAME, luaopen_math },
			{ LUA_DBLIBNAME, luaopen_debug },
			{ LUA_LOADLIBNAME, luaopen_package }
		};

		for( size_t i = 0; i < __libs_count; ++i )
		{
			size_t mask = 1 << i;
			if( (libs & mask) == mask )
			{
				const luaL_Reg* lib = __lualibs + i;
				lua_pushcfunction(m_LuaVM, lib->func);
				lua_pushstring(m_LuaVM, lib->name);
				lua_call(m_LuaVM, 1, 0);
			}
		}
	}

	template<typename AllocationPolicy>
	lua_State* InterpreterBase<AllocationPolicy>::getVirtualMachine() const
	{
		lua_State* state = m_ThreadSpecificStates.get();

		if(!state)
		{
			state = lua_newthread( m_LuaVM );
			lua_pop( m_LuaVM, 1 );

			const_cast<InterpreterBase<AllocationPolicy>*>(this)->m_ThreadSpecificStates.set( state );
		}

		return state;
	}
}
#endif // Interpreter_h__
