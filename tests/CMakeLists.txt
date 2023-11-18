set(TARGET_NAME brasstacks_tests)

file(
    GLOB_RECURSE TARGET_SOURCE
    "${CMAKE_SOURCE_DIR}/tests/*.cpp"
)
file(
    GLOB_RECURSE TARGET_HEADERS
    "${CMAKE_SOURCE_DIR}/tests/*.hpp"
)

add_executable(
    ${TARGET_NAME} EXCLUDE_FROM_ALL
	${TARGET_SOURCE}
    ${TARGET_HEADERS}
)

target_include_directories(
    ${TARGET_NAME} PRIVATE
    ${CMAKE_SOURCE_DIR}/include/
)

target_link_libraries(
    ${TARGET_NAME} PRIVATE
    brasstacks_log
)

set_target_properties(
	${TARGET_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF

	RUNTIME_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/debug/bin
	RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release/bin
)
