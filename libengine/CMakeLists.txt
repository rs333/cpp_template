add_executable( TestEngine )

target_sources( TestEngine
	PRIVATE
		${TST}/TestEngine.cpp
		${INC}/Engine.h
		${SRC}/Engine.cpp
)
include_directories(
	include
)
target_link_libraries( TestEngine gtest_main)

add_test( NAME ENGINE COMMAND TestEngine )