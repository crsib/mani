cmake_minimum_required ( VERSION 2.8.10 )

project( mani )

SET( mani_INCLUDES 
	./mani/details/DefaultAllocatorPolicy.h
	./mani/details/default_stack_ops.h
	./mani/details/mani_internal.h
	./mani/details/RegistryReference.h
	./mani/details/thread_local.h

	./mani/details/impl/Interpreter.h

	./mani/Function.h
	./mani/Interpreter.h
	./mani/mani.h
	./mani/Result.h
	./mani/ValueReference.h
)

source_group( "mani" FILES 
	mani/Function.h
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
)

source_group( "mani\\details\\impl" FILES
	./mani/details/impl/Interpreter.h
)

include_directories( . )
add_library( mani STATIC ${mani_INCLUDES} fake.cpp )
set_target_properties ( mani PROPERTIES FOLDER "tests" )

# Build 'Tests'
find_package( Lua51 REQUIRED )
include_directories( ${LUA_INCLUDE_DIR}  )

add_subdirectory( tests )