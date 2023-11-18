cmake_minimum_required(VERSION 3.20)

project(
    brasstacks_log
    VERSION 0.0.1
    DESCRIPTION "A simple wrapper for spdlog."
    LANGUAGES CXX
)

add_subdirectory(src)
add_subdirectory(test)