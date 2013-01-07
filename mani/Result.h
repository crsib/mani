//  ==================================================================================
//
//  File:        Result.h
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

#ifndef mani_Result_h__
#define mani_Result_h__

#include "mani/details/mani_internal.h"
#include "mani/Interpreter.h"

namespace mani
{
	template<typename AllocationPolicy>
	class   Result : public details::mani_object<AllocationPolicy>
	{
	public:
		Result();
		Result( const Result& rhs );
		Result& operator = ( const Result& rhs );

		Result( const InterpreterBase<AllocationPolicy>& vm, int values_count, bool is_error = false );

		~Result();

		ValueReference<AllocationPolicy>        get( size_t idx = 0 ) const;
		const char*                             getError() const;
		bool                                    isError() const;

		template<typename T>
		T                                       get( size_t idx = 0 ) const;
	private:
		ValueReference<AllocationPolicy>*       m_Results;
		size_t                                  m_ResultsCount;
		bool                                    m_IsError;
	};
}

#endif // Result_h__