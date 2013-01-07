#ifndef mani_FunctionReference_h__
#define mani_FunctionReference_h__

#include "mani/ValueReference.h"

namespace mani
{
	template<typename AllocationPolicy>
	class FunctionReference : public ValueReference<AllocationPolicy>
	{
	public:

		FunctionReference( );

		FunctionReference( const FunctionReference& rhs );
		FunctionReference& operator = ( const FunctionReference& rhs );

		FunctionReference( const ValueReference& rhs );
		FunctionReference& operator = ( const ValueReference& rhs );

		FunctionReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos );

	};
}

#endif // mani_FunctionReference_h__
