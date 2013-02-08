//  ==================================================================================
//
//  File:        ValueReference.h
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
#ifndef mani_impl_ValueReference_h__
#define mani_impl_ValueReference_h__

#include "mani/ValueReference.h"
#include "mani/details/StackGuard.h"
#include "mani/TableReference.h"
#include "mani/FunctionReference.h"
#include "mani/details/StackGuard.h"
#include "mani/Result.h"

namespace mani
{

	template<typename AllocationPolicy>
	size_t mani::ValueReference<AllocationPolicy>::getLength() const
	{
		if(!m_VirtualMachine)
			return 0;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard( lua );

		m_Reference.push( lua );
		return lua_objlen( lua, -1 );
	}

	template<typename AllocationPolicy>
	void ValueReference<AllocationPolicy>::push() const
	{
		if(!m_VirtualMachine)
			return ;

		m_Reference.push( m_VirtualMachine->getVirtualMachine() );
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy> ValueReference<AllocationPolicy>::getMetaTable() const
	{
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);
		
		m_Reference.push( lua );

		if ( lua_getmetatable(lua, -1) != 0 )
			lua_remove(lua, -2);
		else
		{
			lua_pop(lua, 1);
			lua_pushnil(lua);
		}

		return TableReference<AllocationPolicy>( *m_VirtualMachine, 1 );
	}

	template<typename AllocationPolicy>
	void ValueReference<AllocationPolicy>::setMetaTable( const TableReference<AllocationPolicy>& meta )
	{
		if(!m_VirtualMachine)
			return ;

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		m_Reference.push( lua );
		meta.m_Reference.push( lua );

		lua_setmetatable( lua, -2 );
	}

	template<typename AllocationPolicy>
	TableReference<AllocationPolicy> ValueReference<AllocationPolicy>::getTableReference() const
	{
		return TableReference<AllocationPolicy>( *this );
	}

	template<typename AllocationPolicy>
	FunctionReference<AllocationPolicy> ValueReference<AllocationPolicy>::getFunctionReference() const
	{
		return FunctionReference<AllocationPolicy>( *this );
	}

	template<typename AllocationPolicy>
	template<typename T>
	T ValueReference<AllocationPolicy>::get() const
	{
		if(!m_VirtualMachine)
			return T();

		lua_State* lua = m_VirtualMachine->getVirtualMachine();
		details::StackGuard guard(lua);

		m_Reference.push( lua );
		return get_from_stack<T>( lua );
	}

	template<typename AllocationPolicy>
	typename ValueReference<AllocationPolicy>::Type ValueReference<AllocationPolicy>::getType() const
	{ return m_Type; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isThread() const
	{ return m_Type == Thread; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isUserData() const
	{ return m_Type == UserData; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isCFunction() const
	{ return m_IsCFunction; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isFunction() const
	{ return m_Type == ValueReference<AllocationPolicy>::Function; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isTable() const
	{ return m_Type == ValueReference<AllocationPolicy>::Table; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isString() const
	{ return m_Type == ValueReference<AllocationPolicy>::String; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isNumber() const
	{ return m_Type == ValueReference<AllocationPolicy>::Number; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isLightUserData() const
	{ return m_Type == ValueReference<AllocationPolicy>::LightUserData; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isBoolean() const
	{ return m_Type == ValueReference<AllocationPolicy>::Boolean; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isNil() const
	{ return m_Type == ValueReference<AllocationPolicy>::NIL; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isInvalid() const
	{ return m_Type == ValueReference<AllocationPolicy>::None; }

	template<typename AllocationPolicy>
	bool ValueReference<AllocationPolicy>::isInvalidOrNil() const
	{ return isNil() || isInvalid() ; }

	template<typename AllocationPolicy>
	template<typename T>
	ValueReference<AllocationPolicy>
		ValueReference<AllocationPolicy>::new_value( const InterpreterBase<AllocationPolicy>& vm, const T& initializer )
	{
		lua_State* lua = vm.getVirtualMachine();
		details::StackGuard guard(lua);

		push_to_stack( lua, initializer );

		return ValueReference<AllocationPolicy>( vm, -1 );
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy> ValueReference<AllocationPolicy>::nil_value( const InterpreterBase<AllocationPolicy>& vm )
	{
		lua_State* lua = vm.getVirtualMachine();
		details::StackGuard guard(lua);

		lua_pushnil( lua );

		return ValueReference<AllocationPolicy>( vm, -1 );
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy>::ValueReference( const Result<AllocationPolicy>& result, size_t idx  )
	{
		ValueReference<AllocationPolicy> ref = result.get( idx );

		m_VirtualMachine = ref.m_VirtualMachine;
		m_Reference = ref.m_Reference;
		m_Type = ref.m_Type;
		m_IsCFunction = ref.m_IsCFunction;
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy>::ValueReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos )
	{
		m_VirtualMachine = &vm;

		lua_State* lua = vm.getVirtualMachine();

		assert( stack_pos != 0 );
		assert( abs(stack_pos) <= lua_gettop( lua ) );

		lua_pushvalue( lua, stack_pos );
		m_Type = static_cast<ValueReference<AllocationPolicy>::Type>( lua_type( lua, -1 ) );

		m_IsCFunction = isFunction() && lua_iscfunction( lua, -1 );

		m_Reference = details::RegistryReference<AllocationPolicy>( vm );
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy>& ValueReference<AllocationPolicy>::operator=( const ValueReference<AllocationPolicy>& rhs )
	{
		m_VirtualMachine = rhs.m_VirtualMachine;
		m_Reference = rhs.m_Reference;
		m_Type = rhs.m_Type;
		m_IsCFunction = rhs.m_IsCFunction;

		return *this;
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy>::ValueReference( const ValueReference& rhs )
		: m_VirtualMachine( rhs.m_VirtualMachine ), m_Reference( rhs.m_Reference ), 
		m_Type( rhs.m_Type ), m_IsCFunction( rhs.m_IsCFunction )
	{}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy>::ValueReference()
		: m_VirtualMachine( NULL ), m_Type(None), m_IsCFunction(false)
	{}


	template<typename AllocationPolicy>
	void mani::ValueReference<AllocationPolicy>::reset()
	{
		m_Reference = details::RegistryReference<AllocationPolicy>();
	}
}

#endif // mani_impl_ValueReference_h__
