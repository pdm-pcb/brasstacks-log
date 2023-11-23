#include "brasstacks/log/Log.hpp"

int main() {
    btx::Log::trace("Trace int '{}'!", 123);

    btx::Log::info("Info string literal '{}'!", "lolwut");

    std::string output("something to say");
    btx::Log::warn("Warn string '{}'!", output);

    btx::Log::error("Error float: '{:04f}'!", 3.14159f);

    btx::Log::set_level(btx::Log::Level::WARN);
    btx::Log::info("Now this won't show...");
    btx::Log::warn("...but this will.");

    btx::Log::critical("End of the line.");

    return 0;
}