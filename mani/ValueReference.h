#ifndef mani_ValueReference_h__
#define mani_ValueReference_h__

#include "mani/details/RegistryReference.h"

namespace mani
{
	template<typename AllocationPolicy>
	class InterpreterBase;

	template<typename AllocationPolicy>
	class FunctionReference;

	template<typename AllocationPolicy>
	class TableReference;

	template<typename Type>
	Type    get_from_stack( lua_State* state );

	template<typename AllocationPolicy>
	class ValueReference : public details::mani_object<AllocationPolicy>
	{
	public:
		enum Type
		{
			None          = LUA_TNONE,
			NIL           = LUA_TNIL,
			Boolean       = LUA_TBOOLEAN,
			LightUserData = LUA_TLIGHTUSERDATA,
			Number        = LUA_TNUMBER,
			String        = LUA_TSTRING,
			Table         = LUA_TTABLE,
			Function      = LUA_TFUNCTION,
			UserData      = LUA_TUSERDATA,
			Thread        = LUA_TTHREAD
		};

		ValueReference( );

		ValueReference( const ValueReference& rhs );
		ValueReference& operator = ( const ValueReference& rhs );

		ValueReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos );

		template<typename Type>
		static ValueReference<AllocationPolicy> new_value( const InterpreterBase<AllocationPolicy>& vm, const Type& initializer );

		static ValueReference<AllocationPolicy> nil_value( const InterpreterBase<AllocationPolicy>& vm );

		bool           isNil() const;
		bool           isBoolean() const;
		bool           isLightUserData() const;
		bool           isNumber() const;
		bool           isString() const;
		bool           isTable() const;
		bool           isFunction() const;
		bool           isCFunction() const;
		bool           isUserData() const;
		bool           isThread() const;
		bool           isInvalid() const;
		bool           isInvalidOrNil() const;

		Type           getType() const;

		template<typename T>
		T              get() const;

		FunctionReference<AllocationPolicy> getFunctionReference() const;
		TableReference<AllocationPolicy>    getTableReference() const;

		void           setMetaTable( const TableReference<AllocationPolicy>& meta );
		TableReference<AllocationPolicy> getMetaTable( ) const;

		void           push() const;

		size_t         getLength() const;
	protected:
		const InterpreterBase<AllocationPolicy>*  m_VirtualMachine;
		typedef details::RegistryReference<AllocationPolicy> ref_t;
		ref_t          m_Reference;
		Type           m_Type;
		bool           m_IsCFunction;

		friend         void push_to_stack( lua_State* state, const ValueReference<AllocationPolicy>& val ) { val.m_Reference.push(state); }
	};
}

#include "mani/details/default_stack_ops.h"

#endif // ValueReference_h__
