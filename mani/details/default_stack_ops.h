﻿//  ==================================================================================
//
//  File:        default_stack_ops.h
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
#ifndef mani_details_default_stack_ops_h__
#define mani_details_default_stack_ops_h__

#include "mani/ValueReference.h"

namespace mani
{
#define PUSH_TO_STACK( type, method ) \
	inline \
	void push_to_stack( lua_State* state, type val ) \
	{ assert(lua_checkstack(state, 1)); method(state, val ); } 
 
	PUSH_TO_STACK( int,           lua_pushinteger );
	PUSH_TO_STACK( unsigned,      lua_pushinteger );
	PUSH_TO_STACK( long int,      lua_pushinteger );
	PUSH_TO_STACK( long unsigned, lua_pushinteger );
	PUSH_TO_STACK( short,         lua_pushinteger );
	PUSH_TO_STACK( unsigned short,lua_pushinteger );
	PUSH_TO_STACK( char,          lua_pushinteger );

	PUSH_TO_STACK( bool,          lua_pushboolean );

	PUSH_TO_STACK( float,         lua_pushnumber );
	PUSH_TO_STACK( double,        lua_pushnumber );

	PUSH_TO_STACK( lua_CFunction, lua_pushcfunction );
	PUSH_TO_STACK( void*,         lua_pushlightuserdata );

	PUSH_TO_STACK( char*,         lua_pushstring );
	PUSH_TO_STACK( const char*,   lua_pushstring );

#define GET_FROM_STACK( type, method ) \
	template<> inline\
	type    get_from_stack<type>( lua_State* state, int pos ) { return (type)method( state, pos ); }

	GET_FROM_STACK( int,           lua_tointeger );
	GET_FROM_STACK( unsigned,      lua_tointeger );
	GET_FROM_STACK( long int,      lua_tointeger );
	GET_FROM_STACK( long unsigned, lua_tointeger );
	GET_FROM_STACK( short,         lua_tointeger );
	GET_FROM_STACK( unsigned short,lua_tointeger );
	GET_FROM_STACK( char,          lua_tointeger );

#ifdef _MSC_VER
#pragma warning(push)
#pragma warning(disable:4800)
#endif
	GET_FROM_STACK( bool,          lua_toboolean );
#ifdef _MSC_VER
#pragma warning(pop)
#endif


	GET_FROM_STACK( float,         lua_tonumber   );
	GET_FROM_STACK( double,        lua_tonumber   );

	GET_FROM_STACK( lua_CFunction, lua_tocfunction );
	GET_FROM_STACK( void*,         lua_touserdata );

	template<> inline
	const char*    get_from_stack<const char*>( lua_State* state, int pos ) { return lua_isnil( state, -1 ) ? "" : (const char*)lua_tostring( state, -1 ); }
	
#undef PUSH_TO_STACK
#undef GET_FROM_STACK
}

#endif // mani_details_default_stack_ops_h__
