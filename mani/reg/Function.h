//  ==================================================================================
//
//  File:        Function.h
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

#ifndef mani_reg_Function_h__
#define mani_reg_Function_h__

namespace mani
{
	namespace reg
	{
		namespace __private
		{
			template<typename LuaInterpType, typename StringType>
			struct FunctionImpl;
		}

		template<int upvalues, typename LuaInterpType, typename StringType, typename F>
		__private::FunctionImpl<LuaInterpType, StringType>  function( const LuaInterpType& lua, const StringType& function_name, F fn );

		template< typename LuaInterpType, typename StringType, typename F>
		__private::FunctionImpl<LuaInterpType, StringType>  function( const LuaInterpType& lua, const StringType& function_name, F fn );

		template<int upvalues, typename LuaInterpType, typename StringType>
		__private::FunctionImpl<LuaInterpType, StringType>  cfunction( const LuaInterpType& lua, const StringType& function_name, lua_CFunction fn );

		template< typename LuaInterpType, typename StringType>
		__private::FunctionImpl<LuaInterpType, StringType>  cfunction( const LuaInterpType& lua, const StringType& function_name, lua_CFunction fn );
	}
}

#endif // mani_reg_Function_h__
