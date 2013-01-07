//  ==================================================================================
//
//  File:        Interpreter.h
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
#ifndef mani_impl_Interpreter_h__
#define mani_impl_Interpreter_h__

#include "mani/Interpreter.h"
#include "mani/details/StackGuard.h"

#include <cstring>

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

	namespace details
	{
		inline const char* get_buffer_id( const char* name, size_t length )
		{
			static char __id[16];
			size_t max_idx = length > 13 ? 13 : length;
			size_t idx = 0;
			for( ; idx < max_idx; ++idx )
				__id[idx] = name[idx];
			__id[idx++] = '.'; __id[idx++] = '.'; __id[idx++] = '.';
			__id[idx] = '\0';
			return __id;
		}
	}

	template<typename AllocationPolicy>
	typename InterpreterBase<AllocationPolicy>::Result mani::InterpreterBase<AllocationPolicy>::doBuffer( const char* string, size_t size, const Table& env )
	{
		lua_State* lua = getVirtualMachine();
		details::StackGuard guard( lua );
		int top = lua_gettop( lua );

		bool error_occured = 0 != luaL_loadbuffer( lua, string, size, details::get_buffer_id( string, size ) );
		if( !error_occured )
		{
			env.push();
			lua_setfenv( lua, -2 );
			error_occured = 0 != lua_pcall( lua, 0, LUA_MULTRET, 0);
		}

		return Result( *this, lua_gettop( lua ) - top, error_occured );
	}

	template<typename AllocationPolicy>
	typename InterpreterBase<AllocationPolicy>::Result mani::InterpreterBase<AllocationPolicy>::doBuffer( const char* string, size_t size )
	{
		lua_State* lua = getVirtualMachine();
		details::StackGuard guard( lua );
		int top = lua_gettop( lua );

		bool error_occured = 0 != luaL_loadbuffer( lua, string, size, details::get_buffer_id( string, size ) );
		if( !error_occured )
			error_occured = 0 != lua_pcall( lua, 0, LUA_MULTRET, 0);

		return Result( *this, lua_gettop( lua ) - top, error_occured );
	}

	template<typename AllocationPolicy>
	typename InterpreterBase<AllocationPolicy>::Result mani::InterpreterBase<AllocationPolicy>::doString( const char* string, const Table& env )
	{ return doBuffer( string, strlen( string ), env ); }

	template<typename AllocationPolicy>
	typename InterpreterBase<AllocationPolicy>::Result mani::InterpreterBase<AllocationPolicy>::doString( const char* string )
	{ return doBuffer( string, strlen( string ) ); }

	template<typename AllocationPolicy>
	typename InterpreterBase<AllocationPolicy>::Result mani::InterpreterBase<AllocationPolicy>::doFile( const char* path, const Table& env )
	{
		lua_State* lua = getVirtualMachine();
		details::StackGuard guard( lua );
		int top = lua_gettop( lua );

		bool error_occured = 0 != luaL_loadfile( lua, path );
		if( !error_occured )
		{
			env.push();
			lua_setfenv( lua, -2 );
			error_occured = 0 != lua_pcall( lua, 0, LUA_MULTRET, 0);
		}

		return Result( *this, lua_gettop( lua ) - top, error_occured );
	}

	template<typename AllocationPolicy>
	typename InterpreterBase<AllocationPolicy>::Result mani::InterpreterBase<AllocationPolicy>::doFile( const char* path )
	{
		lua_State* lua = getVirtualMachine();
		details::StackGuard guard( lua );
		int top = lua_gettop( lua );

		bool error_occured = 0 != luaL_loadfile( lua, path );
		if( !error_occured )
			error_occured = 0 != lua_pcall( lua, 0, LUA_MULTRET, 0);

		return Result( *this, lua_gettop( lua ) - top, error_occured );
	}
}
#endif // Interpreter_h__
