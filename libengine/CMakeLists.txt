# Avoid relative paths Policy CMP0076
set( INC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set( SRC "${CMAKE_CURRENT_SOURCE_DIR}/src" )
set( TST "${CMAKE_CURRENT_SOURCE_DIR}/tests")

add_library( libengine )

target_include_directories( libengine 
	PUBLIC
		${INC}
)

target_sources( libengine	
	PUBLIC 
		${INC}/Engine.h
	PRIVATE
		${SRC}/Engine.cpp
)

add_executable( TestEngine ${TST}/TestEngine.cpp)
target_link_libraries( TestEngine libengine gtest_main)

add_test( NAME ENGINE COMMAND TestEngine )
