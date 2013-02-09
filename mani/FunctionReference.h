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
#ifndef mani_FunctionReference_h__
#define mani_FunctionReference_h__

#include "mani/ValueReference.h"
#include "mani/TableReference.h"
#include "mani/Result.h"

namespace mani
{
	template<typename AllocationPolicy>
	class FunctionReference : public ValueReference<AllocationPolicy>
	{
	public:
		FunctionReference( );

		FunctionReference( const FunctionReference& rhs );
		FunctionReference<AllocationPolicy>& operator = ( const FunctionReference& rhs );

		FunctionReference( const ValueReference<AllocationPolicy>& rhs );
		FunctionReference<AllocationPolicy>& operator = ( const ValueReference<AllocationPolicy>& rhs );

		FunctionReference( const InterpreterBase<AllocationPolicy>& vm, int stack_pos );

		void             setEnvironment( const TableReference<AllocationPolicy>& env );
		void             setGlobalEnvironment();

		Result<AllocationPolicy> call() const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).call(); }
		template<typename T1>
		Result<AllocationPolicy> call( T1 arg1 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).call(); }
		template<typename T1, typename T2>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).call(); }
		template<typename T1, typename T2, typename T3>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).call(); }
		template<typename T1, typename T2, typename T3, typename T4>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).arg(arg9).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
		Result<AllocationPolicy> call( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).arg(arg9).arg(arg10).call(); }

		Result<AllocationPolicy> operator () () const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).call(); }
		template<typename T1>
		Result<AllocationPolicy> operator () ( T1 arg1 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).call(); }
		template<typename T1, typename T2>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).call(); }
		template<typename T1, typename T2, typename T3>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).call(); }
		template<typename T1, typename T2, typename T3, typename T4>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).arg(arg9).call(); }
		template<typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10>
		Result<AllocationPolicy> operator () ( T1 arg1, T2 arg2, T3 arg3, T4 arg4, T5 arg5, T6 arg6, T7 arg7, T8 arg8, T9 arg9, T10 arg10 ) const
        { return __call_gate( ValueReference<AllocationPolicy>::m_VirtualMachine, *this).arg(arg1).arg(arg2).arg(arg3).arg(arg4).arg(arg5).arg(arg6).arg(arg7).arg(arg8).arg(arg9).arg(arg10).call(); }
	private:
		struct __call_gate
		{
			__call_gate( const InterpreterBase<AllocationPolicy>* vm, const FunctionReference<AllocationPolicy>& __ref );
			
			template<typename T>
			__call_gate&      arg( T __ );

			Result<AllocationPolicy> call();

			const InterpreterBase<AllocationPolicy>* VM;
			lua_State*      Lua;
			int             StackTop;
			int             ArgsOnStack;
		};

		TableReference<AllocationPolicy>m_Environment;
	};
}

#endif // mani_FunctionReference_h__
