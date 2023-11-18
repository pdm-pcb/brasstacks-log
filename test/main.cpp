#include "brasstacks/log/ConsoleLog.hpp"

int main() {
    btx::ConsoleLog::init(btx::ConsoleLog::Level::TRACE);

    btx::ConsoleLog::trace("Trace int '{}'!", 123);

    btx::ConsoleLog::info("Info string literal '{}'!", "lolwut");

    std::string output("something to say");
    btx::ConsoleLog::warn("Warn string '{}'!", output);

    btx::ConsoleLog::error("Error float: '{:04f}'!", 3.14159f);

    return 0;
}