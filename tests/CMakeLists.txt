find_package(Threads REQUIRED)
#basics
add_executable( basics_test basics/main.cpp )
target_link_libraries( basics_test ${LUA_LIBRARIES} ${CMAKE_THREAD_LIBS_INIT} )
set_target_properties ( basics_test PROPERTIES FOLDER "tests" )
