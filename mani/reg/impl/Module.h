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

#ifndef mani_reg_impl_Module_h__
#define mani_reg_impl_Module_h__

namespace mani
{
	namespace reg
	{
		namespace __private
		{
			template<typename LuaInterpType>
			struct ModuleImpl
			{
				template<typename StringType>
				ModuleImpl( const LuaInterpType& lua, const StringType& module_name )
					: Lua( lua )
				{
					lua_State* l = Lua.getVirtualMachine();
					StackTop = lua_gettop( l );

					impl::check_stack_top_table( l );
					if( impl::push_table( l, module_name ) )
					{
						details::StackGuard guard( l );

						typename LuaInterpType::Table mod_reg = lua.getVMModulesRegistry();
						int next_idx = mod_reg.getLength() + 1;

                        typedef typename LuaInterpType::Table table_t;

                        table_t module_meta = table_t::new_table( lua );
                        module_meta.setMetaField( table_t::MetaIndex, module_meta );

						push_to_stack( l, module_meta );

						lua_pushvalue( l, -1 );
						lua_pushcclosure( l, mani::reg::impl::__meta_new_index, 1 );
						lua_setfield( l, -2, "__newindex" );

						lua_setmetatable( l, -2 );

                        mod_reg.setField( next_idx, module_meta );
					}
				}

				~ModuleImpl()
				{ lua_settop( Lua.getVirtualMachine(), StackTop ); }

				int operator [] ( int )
				{ return 0;	}

				const LuaInterpType&   Lua;
				int              StackTop;
			};
		}

		template<typename LuaInterpType, typename StringType>
        __private::ModuleImpl<LuaInterpType> module( const LuaInterpType& lua, const StringType& module_name )
		{
			return __private::ModuleImpl<LuaInterpType>( lua, module_name );
		}
	}
}
#endif // mani_reg_impl_Module_h__
