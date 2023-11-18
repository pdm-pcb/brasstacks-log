set(TARGET_NAME brasstacks_log)

file(
    GLOB_RECURSE TARGET_SOURCE
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
)
file(
    GLOB_RECURSE TARGET_HEADERS
    "${CMAKE_SOURCE_DIR}/include/*.hpp"
)

add_library(
    ${TARGET_NAME} STATIC
	${TARGET_SOURCE}
    ${TARGET_HEADERS}
)

target_include_directories(
    ${TARGET_NAME} PUBLIC
    ${CMAKE_SOURCE_DIR}/include/
)

target_link_libraries(
    ${TARGET_NAME} PUBLIC
    spdlog
)

if(CMAKE_CXX_COMPILER_ID MATCHES "GNU" OR
   CMAKE_CXX_COMPILER_ID MATCHES "Clang")
    target_compile_options(
        ${TARGET_NAME} PRIVATE
        "-Wall"         # Enable most warnings
        "-Wextra"
        "-pedantic"     # and language compliance checks
        "-Werror"       # Warnings as errors
    )

    if(CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_options(
            ${TARGET_NAME} PRIVATE
            "-O0"       # No optimization
            "-ggdb3"    # All the gdb flags
        )
    elseif(CMAKE_BUILD_TYPE MATCHES "Release")
        target_compile_options(
            ${TARGET_NAME} PRIVATE
            "-O3"       # Healthy optimization
        )
    endif()
elseif(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    target_compile_options(
        ${TARGET_NAME} PRIVATE
        "/Wall"         # All warnings not disabled by default
        "/WX"           # Warnings as errors
    )

    if(CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_options(
            ${TARGET_NAME} PRIVATE
            "/Od"       # Optimization disabled
            "/Zi"		# Generate .pdb files: implies /debug
            "/JMC"      # Just-My-Code: only step over user code
            "/RTCs"     # Runtime checks for stack frame behaviors
            "/RTCu"     # Runtime checks for uninitialized variables
            "/GS"       # Buffer overrun checks
            "/sdl"      # Compile and runtime security checks
            "/diagnostics:column" # Include column in compiler messages
        )
    elseif(CMAKE_BUILD_TYPE MATCHES "Release")
        target_compile_options(
            ${TARGET_NAME} PRIVATE
            "/O2"       # Optimization not disabled =D
        )
    endif()
endif()

set_target_properties(
	${TARGET_NAME} PROPERTIES
	CXX_STANDARD 20
	CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF

	ARCHIVE_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/debug/lib
    LIBRARY_OUTPUT_DIRECTORY_DEBUG   ${CMAKE_SOURCE_DIR}/debug/lib

	ARCHIVE_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release/lib
	LIBRARY_OUTPUT_DIRECTORY_RELEASE ${CMAKE_SOURCE_DIR}/release/lib
)
