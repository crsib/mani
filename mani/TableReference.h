#ifndef mani_TableReference_h__
#define mani_TableReference_h__

#include "mani/ValueReference.h"

namespace mani
{
	template<typename AllocationPolicy>
	class TableReference : public ValueReference<AllocationPolicy>
	{
	public:

		TableReference( );

		TableReference( const TableReference& rhs );
		TableReference& operator = ( const TableReference& rhs );

		TableReference( const ValueReference<AllocationPolicy>& rhs );
		TableReference& operator = ( const ValueReference<AllocationPolicy>& rhs );

		TableReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos );

		static TableReference<AllocationPolicy> new_table( const InterpreterBase<AllocationPolicy>& interpreter );
		static TableReference<AllocationPolicy> global( const InterpreterBase<AllocationPolicy>& interpreter );

		bool                             hasField( ValueReference<AllocationPolicy> const & key ) const;

		template<typename KeyType>
		bool                             hasField( KeyType const & key ) const;

		ValueReference<AllocationPolicy> getField( ValueReference<AllocationPolicy> const & key, bool raw = false  ) const;

		template<typename KeyType>
		ValueReference<AllocationPolicy> getField( KeyType const & key, bool raw = false  ) const;

		template<typename KeyType, typename ValueType>
		void                             getField( KeyType const & key, ValueType& value, bool raw = false ) const;

		void                             setField( ValueReference<AllocationPolicy> const & key, const ValueReference<AllocationPolicy>& value, bool raw = false  );

		template<typename KeyType>
		void                             setField( KeyType const & key, const ValueReference<AllocationPolicy>& value, bool raw = false  );

		template<typename KeyType, typename ValueType>
		void                             setField( KeyType const & key, ValueType const & value, bool raw = false  );

		enum MetaMethod
		{
			MetaAdd = 0,          
			MetaSub,      
			MetaMul,      
			MetaDiv,        
			MetaNegate,

			MetaConcat,   

			MetaEqual,         
			MetaLess,    
			MetaLessEqual, 

			MetaToString,     
			
			MetaIndex,
			MetaNewIndex,
			
			MetaGC,

			MethodsCount
		};

		void                             setMetaField( MetaMethod method, const ValueReference<AllocationPolicy>& value );

	private:
		bool      m_IsGlobal; // If this is true - then all the accessors will use LUA_GLOABALSINDEX

		int                              prepare( lua_State* lua ) const;
	};
}

#endif // mani_TableReference_h__
