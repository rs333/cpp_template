
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

add_executable( TestGDAL )
target_sources( TestGDAL
	PRIVATE
		${TST}/TestGDAL.cpp
)
target_link_libraries( TestGDAL
    gtest_main
    GDAL::GDAL
)

add_custom_command( TARGET TestGDAL
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
      ${CMAKE_CURRENT_SOURCE_DIR}/resources/test.tif
      ${CMAKE_CURRENT_BINARY_DIR}
    )

add_test( NAME GDAL COMMAND TestGDAL )
