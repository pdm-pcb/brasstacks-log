#include "brasstacks/log/ConsoleLog.hpp"

#include <cstdio>
#include <format>

#include <chrono>

namespace btx {

void ConsoleLog::trace(std::string_view const msg) {
    auto const formatted_msg = _format(Colors::reset, msg);
    ::fprintf(stdout, "%s\n", formatted_msg.c_str());
}

void ConsoleLog::info(std::string_view const msg) {
    auto const formatted_msg = _format(Colors::green, msg);
    ::fprintf(stdout, "%s\n", formatted_msg.c_str());
}

void ConsoleLog::warn(std::string_view const msg) {
    auto const formatted_msg = _format(Colors::yellow, msg);
    ::fprintf(stderr, "%s\n", formatted_msg.c_str());
}

void ConsoleLog::error(std::string_view const msg) {
    auto const formatted_msg = _format(Colors::red, msg);
    ::fprintf(stderr, "%s\n", formatted_msg.c_str());
}

// =============================================================================
std::string ConsoleLog::_format(char const *color, std::string_view const msg) {
    static auto const *tz = std::chrono::current_zone();
    auto const now = std::chrono::time_point_cast<std::chrono::milliseconds>(
        tz->to_local(std::chrono::system_clock::now())
    );

    return std::format(
        "{:s}[{:%H:%M:%S}] {:s}{:s}",
        color,
        now,
        msg,
        Colors::reset
    );
}

} // namespace btx