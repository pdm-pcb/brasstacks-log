#include "brasstacks/log/ConsoleLog.hpp"

int main() {
    btx::ConsoleLog::set_level(btx::ConsoleLog::Level::TRACE);

    BTX_TRACE("Trace int '{}'!", 123);

    BTX_INFO("Info string literal '{}'!", "lolwut");

    std::string output("something to say");
    BTX_WARN("Warn string '{}'!", output);

    BTX_ERROR("Error float: '{:04f}'!", 3.14159f);

    btx::ConsoleLog::set_level(btx::ConsoleLog::Level::WARN);
    BTX_INFO("Now this won't show...");
    BTX_WARN("...but this will.");

    BTX_CRITICAL("End of the line.");

    return 0;
}