//  ==================================================================================
//
//  File:        TableUtils.h
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
#ifndef mani_reg_TableUtils_h__
#define mani_reg_TableUtils_h__


#include "mani/details/mani_internal.h"

namespace mani
{
	namespace reg
	{
		namespace impl
		{
			// If the stack top is a a table - does nothing
			// Otherwise - pushes _G on to the stack.
			// Return true, if the global was pushed onto the stack
			inline 
			bool       check_stack_top_table( lua_State* l )
			{
				if( !lua_gettop( l ) || !lua_istable( l, -1 ) )
				{
					lua_pushvalue( l, LUA_GLOBALSINDEX );
					return true;
				}
				return false;
			}

			// Requires a table on the stack top
			// Searches for a table, with the name \a name in the stack top table
			// If no table exists - creates it
			// If the table contains field with name \a name, which is not a table, error is generated
			// The table with the name \a name is pushed on to the stack
			template<typename StringType>
			bool       push_table( lua_State* l, const StringType& module_name )
			{
				push_to_stack( l, module_name );
				lua_gettable( l, -2 );

				if( lua_isnil( l, -1 ) )
				{
					lua_pop( l, 1 );

					lua_newtable( l );
					push_to_stack( l, module_name );
					lua_pushvalue( l, -2 );
					lua_settable( l, -4 );

					return true;
				}
				else if( !lua_istable( l, -1 ) )
				{
					lua_pop( l, 1 );
					lua_pushfstring( l, "Field to create module" );
					lua_error( l );
				}

				return false;
			}

			inline
			int __meta_new_index( lua_State* l )
			{
				details::StackGuard guard( l );
				lua_pushvalue( l, lua_upvalueindex( 1 ) );
				lua_pushvalue( l, -3 ); 
				lua_rawget( l, -2 ); 

				if( !lua_isnil( l, -1 ) )
				{
					lua_pushstring( l, "Trying to modify the protected value");
					lua_error( l );
				}

				lua_pop( l, 2 );
				lua_rawset( l, -3 );
				return 0;
			}
		}
	}
}
#endif // mani_reg_TableUtils_h__
