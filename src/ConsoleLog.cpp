#include "brasstacks/log/ConsoleLog.hpp"
#include "version.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace btx {

// =============================================================================
void ConsoleLog::set_level(Level log_level) {
    // Ensure we only set these values one time
    static std::once_flag initialized;
    std::call_once(initialized, [] {
        // Grab a threadsafe logger that supports colorized output
        auto const logger = spdlog::stdout_color_mt("logger");
        spdlog::set_default_logger(logger);

        // The format string requests color, time with milliseconds, thread ID,
        // and the name of the function in which the logging macro was expanded
        spdlog::set_pattern("%^[%T.%e][%t][%!]: %v%$");
    });

    // Set the severity to print
    switch(log_level) {
        case Level::TRACE:    spdlog::set_level(spdlog::level::trace);    break;
        case Level::INFO:     spdlog::set_level(spdlog::level::info);     break;
        case Level::WARN:     spdlog::set_level(spdlog::level::warn);     break;
        case Level::ERROR:    spdlog::set_level(spdlog::level::err);      break;
        case Level::CRITICAL: spdlog::set_level(spdlog::level::critical); break;
    }
}

} // namespace btx