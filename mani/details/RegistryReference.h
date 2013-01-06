#ifndef mani_RegistryReference_h__
#define mani_RegistryReference_h__

#include "mani/details/mani_internal.h"

namespace mani
{
	template<typename AllocationPolicy>
	class InterpreterBase;

	namespace details
	{
		template<typename AllocationPolicy>
		class RegistryReference : protected mani_object<AllocationPolicy>
		{
		public:
			RegistryReference();

			RegistryReference( const InterpreterBase<AllocationPolicy>& vm );

			RegistryReference( const RegistryReference<AllocationPolicy>& rhs );
			RegistryReference& operator = ( const RegistryReference<AllocationPolicy>& rhs );

			~RegistryReference();

			bool                   isValid() const;
			bool                   isNil() const;

			bool                   push( lua_State* lua ) const;

			void                   swap( RegistryReference<AllocationPolicy>& rhs );

		private:
			volatile unsigned long*m_ReferenceCount;
			int                    m_RegistryIndex;
			lua_State*             m_AssociatedVM;
		};
	}
}
#endif // RegistryReference_h__
