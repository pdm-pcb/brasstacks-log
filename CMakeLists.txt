cmake_minimum_required(VERSION 3.25) # Required for FetchContent SYSTEM

project(
    brasstacks_log
    VERSION 0.2.1
    DESCRIPTION "A simple wrapper for spdlog."
    LANGUAGES CXX
)

add_library(${PROJECT_NAME} STATIC)
add_library(brasstacks::log ALIAS ${PROJECT_NAME})

add_subdirectory(src)

# Only touch test when we're not being pulled in by something else
if(PROJECT_IS_TOP_LEVEL)
    add_subdirectory(test)
endif()