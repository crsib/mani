//  ==================================================================================
//
//  File:        Module.h
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
#ifndef mani_reg_Module_h__
#define mani_reg_Module_h__

#include "mani/Interpreter.h"

namespace mani
{
	namespace reg
	{
		namespace __private
		{
			template<typename LuaInterpType>
			struct ModuleImpl;
		}
		
		template<typename LuaInterpType, typename StringType>
		__private::ModuleImpl<LuaInterpType>  module( const LuaInterpType& lua, const StringType& module_name );
	}
}

#endif // mani_reg_Module_h__