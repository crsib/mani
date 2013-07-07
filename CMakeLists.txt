cmake_minimum_required ( VERSION 2.8.10 )

project( mani )

SET( mani_INCLUDES 
	./mani/details/DefaultAllocatorPolicy.h
	./mani/details/default_stack_ops.h
	./mani/details/mani_internal.h
	./mani/details/RegistryReference.h
	./mani/details/thread_local.h
	./mani/details/StackGuard.h

	./mani/details/impl/Interpreter.h
	./mani/details/impl/RegistryReference.h
	./mani/details/impl/ValueReference.h
	./mani/details/impl/FunctionReference.h
	./mani/details/impl/TableReference.h
	./mani/details/impl/Result.h

	./mani/FunctionReference.h
	./mani/TableReference.h
	./mani/Interpreter.h
	./mani/mani.h
	./mani/Result.h
	./mani/ValueReference.h

	./mani/details/functional_utils/Apply.h
	./mani/details/functional_utils/DeduceSignature.h
	./mani/details/functional_utils/Signature.h
	./mani/details/functional_utils/Parameter.h
	./mani/details/functional_utils/BinderProxy.h
	./mani/details/functional_utils/Upvalue.h

	./mani/details/type_utils/Base.h
	./mani/details/type_utils/Out.h
	./mani/details/type_utils/Traits.h
	./mani/details/type_utils/Tuple.h
	./mani/details/type_utils/TypeList.h

	./mani/reg/Class.h
	./mani/reg/Constant.h
	./mani/reg/Constructor.h
	./mani/reg/Enum.h
	./mani/reg/Function.h
	./mani/reg/Method.h
	./mani/reg/Module.h
	./mani/reg/Property.h
	./mani/reg/reg.h
	./mani/reg/StaticMethod.h

	./mani/reg/impl/Class.h
	./mani/reg/impl/Constant.h
	./mani/reg/impl/Constructor.h
	./mani/reg/impl/Enum.h
	./mani/reg/impl/Function.h
	./mani/reg/impl/Method.h
	./mani/reg/impl/Module.h
	./mani/reg/impl/Property.h
	./mani/reg/impl/StaticMethod.h
	./mani/reg/impl/TableUtils.h

)

source_group( "mani" FILES 
	./mani/FunctionReference.h
	./mani/TableReference.h
	./mani/Interpreter.h
	./mani/mani.h
	./mani/Result.h
	./mani/ValueReference.h
)

source_group( "mani\\details" FILES
	./mani/details/DefaultAllocatorPolicy.h
	./mani/details/default_stack_ops.h
	./mani/details/mani_internal.h
	./mani/details/RegistryReference.h
	./mani/details/thread_local.h
	./mani/details/StackGuard.h
)

source_group( "mani\\details\\impl" FILES
	./mani/details/impl/Interpreter.h
	./mani/details/impl/RegistryReference.h
	./mani/details/impl/ValueReference.h
	./mani/details/impl/FunctionReference.h
	./mani/details/impl/TableReference.h
	./mani/details/impl/Result.h
)

source_group( "mani\\details\\type_utils" FILES
	./mani/details/type_utils/Base.h
	./mani/details/type_utils/Out.h
	./mani/details/type_utils/Traits.h
	./mani/details/type_utils/Tuple.h
	./mani/details/type_utils/TypeList.h
)

source_group( "mani\\details\\functional_utils" FILES 
	./mani/details/functional_utils/Apply.h
	./mani/details/functional_utils/DeduceSignature.h
	./mani/details/functional_utils/Signature.h
	./mani/details/functional_utils/Parameter.h
	./mani/details/functional_utils/BinderProxy.h
	./mani/details/functional_utils/Upvalue.h
)

source_group( "mani\\reg" FILES
	./mani/reg/Class.h
	./mani/reg/Constant.h
	./mani/reg/Constructor.h
	./mani/reg/Enum.h
	./mani/reg/Function.h
	./mani/reg/Method.h
	./mani/reg/Module.h
	./mani/reg/Property.h
	./mani/reg/reg.h
	./mani/reg/StaticMethod.h
)

source_group( "mani\\reg\\impl" FILES
	./mani/reg/impl/Class.h
	./mani/reg/impl/Constant.h
	./mani/reg/impl/Constructor.h
	./mani/reg/impl/Enum.h
	./mani/reg/impl/Function.h
	./mani/reg/impl/Method.h
	./mani/reg/impl/Module.h
	./mani/reg/impl/Property.h
	./mani/reg/impl/StaticMethod.h
	./mani/reg/impl/TableUtils.h
)

include_directories( . )
add_library( mani STATIC ${mani_INCLUDES} fake.cpp )
set_target_properties ( mani PROPERTIES FOLDER "tests" )

# Build 'Tests'
find_package( Lua51 REQUIRED )
include_directories( ${LUA_INCLUDE_DIR}  )

add_subdirectory( tests )