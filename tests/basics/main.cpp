//  ==================================================================================
//
//  File:        main.cpp
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
#include "mani/mani.h"

#if defined(PLATFORM_WIN_THREADS)
#include <process.h>

void __cdecl threadproc(void* lparam)
{
	assert( reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() != reinterpret_cast<mani::Interpreter*>(lparam)->getDefaultVirtualMachine() );
	assert( reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() == reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() );
}
#elif defined(PLATFORM_POSIX_THREADS)

#endif

int main( int, char** )
{
	mani::Interpreter lua;

	lua.openStandardLibraries();

#if defined(PLATFORM_WIN_THREADS)
	uintptr_t th = _beginthread( threadproc, 0, &lua);
#elif defined(PLATFORM_POSIX_THREADS)

#endif

	assert( lua.getVirtualMachine() == lua.getDefaultVirtualMachine() );

#if defined(PLATFORM_WIN_THREADS)
	WaitForSingleObject(reinterpret_cast<HANDLE>(th), INFINITE);
#elif defined(PLATFORM_POSIX_THREADS)

#endif

	mani::Interpreter::Value val = mani::Interpreter::Value::new_value<int>( lua, 10 );
	assert( val.get<int>() == 10 );
	
	mani::Interpreter::Table table = mani::Interpreter::Table::global( lua );

	table.setField( "global_value", 10 );
	assert( table.getField("global_value").get<int>() == 10 );

	int global_value;
	table.getField("global_value", global_value );
	assert( global_value == 10 );

	mani::Interpreter::Value key = mani::Interpreter::Value::new_value<const char*>( lua, "global_value");
	assert( table.getField(key).get<int>() == 10 );

	table.setField(key, mani::Interpreter::Value::new_value<const char*>( lua, "text") );

	assert( table.getField(key).getLength() == 4 );

	mani::Interpreter::Table local_table = mani::Interpreter::Table::new_table( lua );
	table.setField( "table", local_table );
	local_table.setField("test",14);

	table = table.getField("table");
	assert( table.getField("test").get<int>() == 14 );

	assert( lua.doString("return 2+2").get<int>() == 4 );
	assert( lua.doString("ab + cd").isError() );

	assert( lua_gettop(lua.getDefaultVirtualMachine()) == 0);
	return 0;
}
