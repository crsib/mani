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

#include "mani/details/type_utils/Tuple.h"
#include "mani/details/functional_utils/DeduceSignature.h"
#include "mani/details/functional_utils/Apply.h"
#include "mani/details/functional_utils/Parameter.h"
#include "mani/details/functional_utils/BinderProxy.h"

#if defined(PLATFORM_WIN_THREADS)
#include <process.h>

void __cdecl threadproc(void* lparam)
{
	assert( reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() != reinterpret_cast<mani::Interpreter*>(lparam)->getDefaultVirtualMachine() );
	assert( reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() == reinterpret_cast<mani::Interpreter*>(lparam)->getVirtualMachine() );
}
#elif defined(PLATFORM_POSIX_THREADS)

#endif

int test_1( int b )
{
	return b * b;
}

int test_2( int a, int b )
{
	return a - b;
}

void test_0()
{}

struct bound_test
{
	int test( int a, int b, int c )
	{
		return a * a - b * c;
	}
};

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

	lua.doString("function sum( a,b ) return a+b end");
	mani::Interpreter::Function sum = mani::Interpreter::Table::global( lua ).getField( "sum" );
	assert( sum( 2, 3 ).get<int>() == 5 );
	
	assert( lua_gettop(lua.getDefaultVirtualMachine()) == 0);

	assert(mani::details::type_utils::Traits<int>::is_arith == 1);
	mani::details::type_utils::Tuple< mani::details::type_utils::Vector< int, float, int >::result_t > tuple1, tuple2;
	mani::details::type_utils::Field<0>(tuple1) = 2;

	tuple2 = tuple1;
	assert(mani::details::type_utils::Field<0>(tuple2) == 2);

	assert(mani::details::type_utils::Field<0>(mani::details::type_utils::make_tuple<int>( 10 ) ) == 10);

	assert( mani::details::functional_utils::deduce_signature( test_0 ).arg_count == 0 );
	assert( mani::details::functional_utils::deduce_signature( test_1 ).arg_count == 1 );
	assert( mani::details::functional_utils::deduce_signature( test_2 ).arg_count == 2 );

    mani::details::functional_utils::apply( mani::details::functional_utils::deduce_signature( test_0 ), reinterpret_cast<mani::details::type_utils::NullType*>(NULL), test_0  );
    assert( 9 == mani::details::functional_utils::apply( mani::details::functional_utils::deduce_signature( test_1 ), reinterpret_cast<mani::details::type_utils::NullType*>(NULL), test_1, mani::details::type_utils::make_tuple<int>( 3 )  ) );

	bound_test b_test;
	assert( 13 == 
		mani::details::functional_utils::apply( mani::details::functional_utils::deduce_signature( &bound_test::test ), &b_test, &bound_test::test, mani::details::type_utils::make_tuple< int, int, int >( 5, 4, 3 ) ) );

	mani::details::functional_utils::binder_proxy( mani::details::functional_utils::deduce_signature( test_1 ) );
	//mani::details::functional_utils::binder_proxy( mani::details::functional_utils::deduce_signature( &bound_test::test ) );

	mani::reg::module(lua, "test")
	[
		5, 6, 7 
	];

	mani::reg::module(lua, "test")
	[
		5, 6, 7 
	];

	return 0;
}
