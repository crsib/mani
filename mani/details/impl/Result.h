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

#ifndef mani_impl_Result_h__
#define mani_impl_Result_h__

#include "mani/Result.h"

namespace mani
{
	template<typename AllocationPolicy>
	const char* Result<AllocationPolicy>::getError() const
	{
		if(m_Results)
			return m_Results[0].get<const char*>();
		return "unknown error";
	}

	template<typename AllocationPolicy>
	ValueReference<AllocationPolicy> Result<AllocationPolicy>::get( size_t idx ) const
	{ return (idx < m_ResultsCount) ? m_Results[ idx ] : ValueReference<AllocationPolicy>(); }

	template<typename AllocationPolicy>
	template<typename T>
	T Result<AllocationPolicy>::get( size_t idx ) const
	{ return get( idx ).get<T>(); }

	template<typename AllocationPolicy>
	Result<AllocationPolicy>::~Result()
	{
		delete [] m_Results;
	}

	template<typename AllocationPolicy>
    Result<AllocationPolicy>::Result( const InterpreterBase<AllocationPolicy>& vm, int values_count, bool is_error )
	{
		m_Results = NULL;
		m_ResultsCount = values_count;
		m_IsError = is_error;

		if(m_ResultsCount)
		{
			m_Results = new ValueReference<AllocationPolicy>[m_ResultsCount];

			for( size_t i = 0; i < m_ResultsCount; ++i )
				m_Results[ i ] = ValueReference<AllocationPolicy>( vm, -static_cast<int>( m_ResultsCount - i ) );
		}
	}

	template<typename AllocationPolicy>
	Result<AllocationPolicy>& Result<AllocationPolicy>::operator=( const Result& rhs )
	{
		m_Results = NULL;
		m_ResultsCount = rhs.m_ResultsCount;
		m_IsError = rhs.m_IsError;

		if(m_ResultsCount)
		{
			m_Results = new ValueReference<AllocationPolicy>[m_ResultsCount];

			for( size_t i = 0; i < m_ResultsCount; ++i )
				m_Results[ i ] = rhs.m_Results[ i ];
		}

		return *this;
	}

	template<typename AllocationPolicy>
	Result<AllocationPolicy>::Result( const Result& rhs )
		: m_Results(NULL), m_ResultsCount(rhs.m_ResultsCount), m_IsError( rhs.m_IsError )
	{
		if(m_ResultsCount)
		{
			m_Results = new ValueReference<AllocationPolicy>[m_ResultsCount];
			
			for( size_t i = 0; i < m_ResultsCount; ++i )
				m_Results[ i ] = rhs.m_Results[ i ];
		}
	}

	template<typename AllocationPolicy>
	Result<AllocationPolicy>::Result()
		: m_Results(NULL), m_ResultsCount(0), m_IsError( false )
	{}


	template<typename AllocationPolicy>
	bool Result<AllocationPolicy>::isError() const
	{
		return m_IsError;
	}
}

#endif // Result_h__
