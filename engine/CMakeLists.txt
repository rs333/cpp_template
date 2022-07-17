# Avoid relative paths Policy CMP0076
set( INC "${CMAKE_CURRENT_SOURCE_DIR}/include")
set( SRC "${CMAKE_CURRENT_SOURCE_DIR}/src" )
set( TST "${CMAKE_CURRENT_SOURCE_DIR}/tests")

add_executable( engine )

target_sources( engine	
	PRIVATE
		${SRC}/Main.cpp
)

target_link_libraries( engine libengine)

add_executable( TestMain ${TST}/TestMain.cpp)
target_link_libraries( TestMain libengine gtest_main)

add_test( NAME ENGINEMAIN COMMAND TestMain )
