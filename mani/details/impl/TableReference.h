//  ==================================================================================
//
//  File:        TableReference.h
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
#ifndef mani_impl_TableReference_h__
#define mani_impl_TableReference_h__

#include "mani/TableReference.h"
#include "mani/details/StackGuard.h"

namespace mani
{
	template<typename AllocationPolicy>
	void TableReference<AllocationPolicy>::setMetaField( MetaMethod method, const ValueReference<AllocationPolicy>& value )
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepareSet( lua );
		
		static const char* __meta_keys[MethodsCount] = { "__add", "__sub", "__mul", "__div", "__unm", "__concat", "__eq", "__lt", "__le", "__tostring", "__index", "__newindex", "__gc" };

		lua_pushstring( lua, __meta_keys[method] );
		value.m_Reference.push( lua );

		if(raw == false)
			lua_settable( lua, idx );
		else
			lua_rawset( lua, idx );
	}

	template<typename AllocationPolicy>
	template<typename KeyType, typename ValueType>
	void TableReference<AllocationPolicy>::setField( KeyType const & key, ValueType const & value, bool raw /*= false */ )
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepareSet( lua );
		push_to_stack( lua, key );
		push_to_stack( lua, value );

		if(raw == false)
			lua_settable( lua, idx );
		else
			lua_rawset( lua, idx );
	}

	template<typename AllocationPolicy>
	template<typename KeyType>
	void TableReference<AllocationPolicy>::setField( KeyType const & key, const ValueReference<AllocationPolicy>& value, bool raw /*= false */ )
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepareSet( lua );
		push_to_stack( lua, key );
		value.m_Reference.push( lua );

		if(raw == false)
			lua_settable( lua, idx );
		else
			lua_rawset( lua, idx );
	}

	template<typename AllocationPolicy>
	void TableReference<AllocationPolicy>::setField( ValueReference<AllocationPolicy> const & key, const ValueReference<AllocationPolicy>& value, bool raw /*= false */ )
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepareSet( lua );
		key.push();
		value.push( );

		if(raw == false)
			lua_settable( lua, idx );
		else
			lua_rawset( lua, idx );
	}

	template<typename AllocationPolicy>
	template<typename KeyType, typename ValueType>
	void
		TableReference<AllocationPolicy>::getField( KeyType const & key, ValueType& value, bool raw /*= false */ ) const
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepare( lua );
		push_to_stack( lua, key );

		if(raw == false)
			lua_gettable( lua, idx );
		else
			lua_rawget( lua, idx );

		value = get_from_stack<ValueType>(lua);
	}

	template<typename AllocationPolicy>
	template<typename KeyType>
	ValueReference<AllocationPolicy>
		TableReference<AllocationPolicy>::getField( KeyType const & key, bool raw /*= false */ ) const
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ValueReference<AllocationPolicy>::nil_value( *m_VirtualMachine );

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepare( lua );
		push_to_stack( lua, key );

		if(raw == false)
			lua_gettable( lua, idx );
		else
			lua_rawget( lua, idx );

		return ValueReference<AllocationPolicy>( *m_VirtualMachine, -1 );
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy> TableReference<AllocationPolicy>::getField( ValueReference<AllocationPolicy> const & key, bool raw /*= false */ ) const
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return ValueReference<AllocationPolicy>::nil_value( *m_VirtualMachine );

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepare( lua );
		key.push( );

		if(raw == false)
			lua_gettable( lua, idx );
		else
			lua_rawget( lua, idx );

		return ValueReference<AllocationPolicy>( *m_VirtualMachine, -1 );
	}

	template<typename AllocationPolicy>
	template<typename KeyType>
	bool TableReference<AllocationPolicy>::hasField( KeyType const & key ) const
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return false;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepare( lua );
		push_to_stack( lua, key );

		lua_rawget( lua, idx );

		return !lua_isnil( lua, -1 );
	}

	template<typename AllocationPolicy>
	bool TableReference<AllocationPolicy>::hasField( ValueReference<AllocationPolicy> const & key ) const
	{
		assert( isTable() );
		if(!m_VirtualMachine)
			return false;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		int idx = prepare( lua );

		key.m_Reference.push( lua );

		lua_rawget( lua, idx );

		return !lua_isnil( lua, -1 );
	}

	template<typename AllocationPolicy>
	int TableReference<AllocationPolicy>::prepare( lua_State* lua ) const
	{
		if( m_IsGlobal )
			return LUA_GLOBALSINDEX;
		m_Reference.push( lua );
		return -2;
	}

	template<typename AllocationPolicy>
	int TableReference<AllocationPolicy>::prepareSet( lua_State* lua ) const
	{
		if( m_IsGlobal )
			return LUA_GLOBALSINDEX;
		m_Reference.push( lua );
		return -3;
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy> TableReference<AllocationPolicy>::global( const InterpreterBase<AllocationPolicy>& interpreter )
	{
		TableReference<AllocationPolicy> table;
		table.m_VirtualMachine = &interpreter;
		table.m_IsGlobal = true;
		table.m_Type = Table;
		return table;
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy> TableReference<AllocationPolicy>::new_table( const InterpreterBase<AllocationPolicy>& interpreter )
	{
		lua_State* lua = interpreter.getVirtualMachine();
		details::StackGuard guard( lua );
		lua_newtable( lua );
		
		return TableReference<AllocationPolicy>( interpreter, -1 );
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy>::TableReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos )
		: ValueReference( vm, stack_pos ), m_IsGlobal(false)
	{ assert( isTable() ); }

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy>& TableReference<AllocationPolicy>::operator=( const ValueReference<AllocationPolicy>& rhs )
	{
		ValueReference<AllocationPolicy>::operator= ( rhs );
		m_IsGlobal = false;
		assert( isTable() ); 
		return *this;
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy>::TableReference( const ValueReference<AllocationPolicy>& rhs )
		: ValueReference<AllocationPolicy>(rhs), m_IsGlobal( false )
	{ assert( isTable() ); }

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy>& TableReference<AllocationPolicy>::operator=( const TableReference& rhs )
	{
		ValueReference<AllocationPolicy>::operator= ( rhs );
		m_IsGlobal = rhs.m_IsGlobal;
		return *this;
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy>::TableReference( const TableReference& rhs )
		: ValueReference<AllocationPolicy>(rhs), m_IsGlobal( rhs.m_IsGlobal )
	{}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy>::TableReference()
		: m_IsGlobal(false)
	{}
}

#endif // mani_impl_TableReference_h__
