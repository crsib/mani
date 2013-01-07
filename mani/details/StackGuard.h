//  ==================================================================================
//
//  File:        StackGuard.h
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
#ifndef mani_details_StackGuard_h__
#define mani_details_StackGuard_h__

#include "mani/details/mani_internal.h"

namespace mani
{
	namespace details
	{
		class StackGuard
		{
		public:
			StackGuard( lua_State* stack );
			~StackGuard();

			int extraItems() const;
			bool check( int n ) const;
		private:
			lua_State*   m_Stack;
			int          m_Top;
		};

		inline
		StackGuard::StackGuard( lua_State* stack )
			: m_Stack( stack ), m_Top( lua_gettop(stack) )	
		{ assert( stack ); }

		inline
		StackGuard::~StackGuard()
		{ lua_settop( m_Stack, m_Top );	}

		inline
		int StackGuard::extraItems() const
		{ return lua_gettop( m_Stack ) - m_Top;	}

		inline
		bool StackGuard::check( int n ) const
		{ return n == extraItems(); }
	}
}

#endif // mani_details_StackGuard_h__
