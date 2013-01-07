//  ==================================================================================
//
//  File:        Interpreter.h
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
#ifndef mani_Interpreter_h__
#define mani_Interpreter_h__

#include "mani/details/mani_internal.h"
#include "mani/details/thread_local.h"

#include "mani/ValueReference.h"
#include "mani/TableReference.h"
#include "mani/FunctionReference.h"
#include "mani/Result.h"

namespace mani
{
	template<typename AllocationPolicy>
	class InterpreterBase : public details::mani_object<AllocationPolicy>
	{
		InterpreterBase( const InterpreterBase& );
		InterpreterBase& operator = ( const InterpreterBase& );
	public:
		InterpreterBase( );
		InterpreterBase( lua_State* lua );
		~InterpreterBase( );

		enum StandardLibraries
		{
			Base         = 1 << 0,
			LibTable     = 1 << 1,
			LibIO        = 1 << 2,
			LibOS        = 1 << 3,
			LibString    = 1 << 4,
			LibMath      = 1 << 5,
			LibDebug     = 1 << 6,
			LibPackage   = 1 << 7,

			AllLibs      = Base | LibTable | LibIO | LibOS | LibString | LibMath | LibDebug | LibPackage
		};

		void            openStandardLibraries( unsigned libs = AllLibs );  

		lua_State*      getDefaultVirtualMachine() const { return m_LuaVM; }
		lua_State*      getVirtualMachine() const;

		typedef ValueReference<AllocationPolicy> Value;
		typedef TableReference<AllocationPolicy> Table;
		typedef FunctionReference<AllocationPolicy> Function;
		typedef Result<AllocationPolicy> Result;

		Result          doFile( const char* path );
		Result          doFile( const char* path, const Table& env );

		Result          doString( const char* string );
		Result          doString( const char* string, const Table& env );

		Result          doBuffer( const char* string, size_t size );
		Result          doBuffer( const char* string, size_t size, const Table& env );

	private:  
		static void*    lua_alloc(void *ud, void *ptr, size_t osize, size_t nsize);

		lua_State*        m_LuaVM;
		details::tl_state m_ThreadSpecificStates;

		bool              m_OwnsState;
	};
}

#include "mani/details/DefaultAllocatorPolicy.h"

namespace mani
{
	typedef InterpreterBase< details::DefaultAllocationPolicy > Interpreter;
}
#endif // Interpreter_h__
