#include "brasstacks/log/ConsoleLog.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE() {
    btx::ConsoleLog::trace("Testing a trace");
    btx::ConsoleLog::info("Testing an info");
    btx::ConsoleLog::warn("Testing a warn");
    btx::ConsoleLog::error("Testing an error");
}