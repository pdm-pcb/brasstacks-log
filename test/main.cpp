#include "brasstacks/log/ConsoleLog.hpp"

int main() {
    btx::ConsoleLog::init(btx::ConsoleLog::Level::TRACE);

    BTX_TRACE("Trace int '{}'!", 123);

    BTX_INFO("Info string literal '{}'!", "lolwut");

    std::string output("something to say");
    BTX_WARN("Warn string '{}'!", output);

    BTX_ERROR("Error float: '{:04f}'!", 3.14159f);

    return 0;
}