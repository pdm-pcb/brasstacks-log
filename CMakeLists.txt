cmake_minimum_required(VERSION 3.20)

project(
    brasstacks_log
    VERSION 0.1.0
    DESCRIPTION "Console logging for learning and video games."
    LANGUAGES CXX C
)

add_subdirectory(src)

if (${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR})
    add_subdirectory(tests)
endif()