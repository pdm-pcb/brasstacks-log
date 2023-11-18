cmake_minimum_required(VERSION 3.20)

project(
    brasstacks_log
    VERSION 0.0.1
    DESCRIPTION "A simple wrapper for spdlog"
    LANGUAGES CXX
)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(FetchDeps)

add_subdirectory(src)
add_subdirectory(tests)