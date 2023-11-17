#include "brasstacks/log/ConsoleLog.hpp"

#include <catch2/catch_test_macros.hpp>

TEST_CASE() {
    using namespace std::chrono_literals;

    btx::ConsoleLog::trace("Testing a trace");
    btx::ConsoleLog::info("Testing an info");
    btx::ConsoleLog::warn("Testing a warn");
    btx::ConsoleLog::error("Testing an error");

    btx::ConsoleLog::dump();

    std::printf("\n\n");
    std::this_thread::sleep_for(250ms);

    btx::ConsoleLog::trace("Testing a trace again");
    btx::ConsoleLog::info("Testing an info again");
    btx::ConsoleLog::warn("Testing a warn again");
    btx::ConsoleLog::error("Testing an error again");

    btx::ConsoleLog::dump();
}