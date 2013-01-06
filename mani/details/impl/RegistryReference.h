#ifndef mani_impl_RegistryReference_h__
#define mani_impl_RegistryReference_h__

#include "mani/details/RegistryReference.h"

#include <algorithm>

namespace mani
{
	namespace details
	{
		template<typename AllocationPolicy>
		RegistryReference<AllocationPolicy>::RegistryReference()
			: m_ReferenceCount(NULL), m_RegistryIndex(LUA_NOREF), m_AssociatedVM( NULL )
		{

		}

		template<typename AllocationPolicy>
		RegistryReference<AllocationPolicy>::RegistryReference( const InterpreterBase<AllocationPolicy>& vm )
			: m_ReferenceCount( NULL ), m_RegistryIndex( LUA_NOREF ), m_AssociatedVM( vm.getDefaultVirtualMachine() )
		{
			lua_State* current_state = vm.getVirtualMachine();
			if( lua_isnoneornil( current_state, 1 ) )
				return ;

			m_ReferenceCount = reinterpret_cast<unsigned long*>( allocate( sizeof( unsigned long ) ) );
			*m_ReferenceCount = 1; 
			m_RegistryIndex = luaL_ref( current_state, LUA_REGISTRYINDEX );
		}

		template<typename AllocationPolicy>
		RegistryReference<AllocationPolicy>::RegistryReference( const RegistryReference<AllocationPolicy>& rhs )
			: m_ReferenceCount( NULL )
		{
			RegistryReference<AllocationPolicy> copy;
			
			if( rhs.isValid() )
			{
				copy.m_ReferenceCount = rhs.m_ReferenceCount;
				MANI_ATOMIC_INC( copy.m_ReferenceCount );
				copy.m_RegistryIndex  = rhs.m_RegistryIndex;
				copy.m_AssociatedVM   = rhs.m_AssociatedVM;
			}

			this->swap( copy );
		}

		template<typename AllocationPolicy>
		RegistryReference<AllocationPolicy>& RegistryReference<AllocationPolicy>::operator=( const RegistryReference<AllocationPolicy>& rhs )
		{
			RegistryReference<AllocationPolicy> copy(rhs);
			this->swap( copy );
			return *this;
		}

		template<typename AllocationPolicy>
		RegistryReference<AllocationPolicy>::~RegistryReference()
		{
			if( m_ReferenceCount && !MANI_ATOMIC_DEC(m_ReferenceCount) )
			{
				deallocate( const_cast<unsigned long*>(m_ReferenceCount), sizeof(long unsigned) );
				luaL_unref( m_AssociatedVM, LUA_REGISTRYINDEX, m_RegistryIndex );
			}
		}

		template<typename AllocationPolicy>
		bool RegistryReference<AllocationPolicy>::isNil() const	{ return m_RegistryIndex == LUA_REFNIL;	}

		template<typename AllocationPolicy>
		bool RegistryReference<AllocationPolicy>::isValid() const
		{ return (m_RegistryIndex != LUA_NOREF) && (m_RegistryIndex != LUA_REFNIL);	}

		template<typename AllocationPolicy>
		bool RegistryReference<AllocationPolicy>::push( lua_State* current_state ) const
		{
			if(!isValid())
			{
				lua_pushnil( current_state );
				return false;
			}

			lua_rawgeti( current_state, LUA_REGISTRYINDEX, m_RegistryIndex );
			return true;
		}

		template<typename AllocationPolicy>
		void RegistryReference<AllocationPolicy>::swap( RegistryReference<AllocationPolicy>& rhs )
		{
			std::swap( m_ReferenceCount, rhs.m_ReferenceCount );
			std::swap( m_RegistryIndex, rhs.m_RegistryIndex );
			std::swap( m_AssociatedVM, rhs.m_AssociatedVM );
		}
	}
}

namespace std
{
	template<typename AllocationPolicy>
	void  swap( mani::details::RegistryReference<AllocationPolicy>& lhs, mani::details::RegistryReference<AllocationPolicy>& rhs )
	{ lhs.swap(rhs); }
}

#endif // mani_impl_RegistryReference_h__
