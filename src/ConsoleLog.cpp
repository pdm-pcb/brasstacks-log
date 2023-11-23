#include "brasstacks/log/Log.hpp"
#include "version.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace btx {

// =============================================================================
void Log::set_level(Level log_level) {
    // Make sure we're set up
    _init();

    // Set the severity to print
    switch(log_level) {
        case Level::TRACE:    spdlog::set_level(spdlog::level::trace);    break;
        case Level::INFO:     spdlog::set_level(spdlog::level::info);     break;
        case Level::WARN:     spdlog::set_level(spdlog::level::warn);     break;
        case Level::ERROR:    spdlog::set_level(spdlog::level::err);      break;
        case Level::CRITICAL: spdlog::set_level(spdlog::level::critical); break;
    }
}

// =============================================================================
void Log::_init() {
    static std::once_flag initialized;
    std::call_once(initialized, [] {
        // Grab a threadsafe logger that supports colorized output
        auto const logger = spdlog::stdout_color_mt("logger");
        spdlog::set_default_logger(logger);

        // Print with color, time with milliseconds, and thread ID
        spdlog::set_pattern("%^[%T.%e][%t]: %v%$");

        // Default to everything
        spdlog::set_level(spdlog::level::trace);

        spdlog::info("brasstacks console logger v{}", BTX_LOG_VER);
    });
}

} // namespace btx