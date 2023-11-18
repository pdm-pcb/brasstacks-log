include(FetchContent)

FetchContent_Declare(
    spdlog EXCLUDE_FROM_ALL SYSTEM
    GIT_REPOSITORY https://github.com/gabime/spdlog
    GIT_TAG 7e635fca68d014934b4af8a1cf874f63989352b7 # 2023-07-08
    FIND_PACKAGE_ARGS 1.12.0
)
set(SPDLOG_USE_STD_FORMAT "ON" CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(spdlog)