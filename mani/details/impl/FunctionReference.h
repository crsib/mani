//  ==================================================================================
//
//  File:        FunctionReference.h
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

#ifndef mani_impl_FunctionReference_h__
#define mani_impl_FunctionReference_h__

#include "mani/FunctionReference.h"

namespace mani
{
	template<typename AllocationPolicy>
	Result<AllocationPolicy> FunctionReference<AllocationPolicy>::__call_gate::call()
	{
		bool is_error = 0 != lua_pcall( Lua, ArgsOnStack, LUA_MULTRET, 0 );
		Result<AllocationPolicy> result( *VM, lua_gettop( Lua ) - StackTop, is_error );
		lua_settop( Lua, StackTop );
		return result;
	}

	template<typename AllocationPolicy>
	template<typename T>
	typename FunctionReference<AllocationPolicy>::__call_gate& FunctionReference<AllocationPolicy>::__call_gate::arg( T __ )
	{
		++ArgsOnStack;
		push_to_stack( Lua, __ );
		return *this;
	}

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>::__call_gate::__call_gate( const InterpreterBase<AllocationPolicy>* vm, const FunctionReference<AllocationPolicy>& __ref )
		: VM(vm), Lua( vm->getVirtualMachine() ), StackTop( lua_gettop( Lua ) ), ArgsOnStack( 0 )

	{
		__ref.m_Reference.push( Lua );

		if( __ref.m_Environment.isTable() )
		{
			push_to_stack( Lua, __ref.m_Environment );
			lua_setfenv( Lua, -2 );
		}
	}

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>::FunctionReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos )
		: ValueReference<AllocationPolicy>( vm, stack_pos )
    { assert( ValueReference<AllocationPolicy>::isFunction() ); }

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>& FunctionReference<AllocationPolicy>::operator=( const ValueReference<AllocationPolicy>& rhs )
	{
		ValueReference<AllocationPolicy>::operator = ( rhs );
        assert( ValueReference<AllocationPolicy>::isFunction() );
		return *this;
	}

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>::FunctionReference( const ValueReference<AllocationPolicy>& rhs )
		: ValueReference<AllocationPolicy>(rhs)
    { assert( ValueReference<AllocationPolicy>::isFunction() ); }

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>& FunctionReference<AllocationPolicy>::operator=( const FunctionReference& rhs )
	{
		ValueReference<AllocationPolicy>::operator = ( rhs );
        FunctionReference<AllocationPolicy>::m_Environment = rhs.m_Environment;
		return *this;
	}

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>::FunctionReference( const FunctionReference& rhs )
        : ValueReference<AllocationPolicy>( rhs )
    { FunctionReference<AllocationPolicy>::m_Environment = rhs.m_Environment; }

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy>::FunctionReference()
	{}

	template<typename AllocationPolicy>
	void FunctionReference<AllocationPolicy>::setGlobalEnvironment()
	{ m_Environment = TableReference<AllocationPolicy>(); }

	template<typename AllocationPolicy>
	void FunctionReference<AllocationPolicy>::setEnvironment( const TableReference<AllocationPolicy>& env )
	{ m_Environment = env; }

}

#endif // mani_impl_FunctionReference_h__
