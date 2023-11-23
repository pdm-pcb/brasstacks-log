#ifndef BRASSTACKS_LOG_CONSOLELOG_HPP
#define BRASSTACKS_LOG_CONSOLELOG_HPP

#include <cstdlib>
#include <format>
#include <spdlog/spdlog.h>

namespace btx {

class ConsoleLog final {
public:
    enum class Level : uint8_t {
        TRACE,
        INFO,
        WARN,
        ERROR,
        CRITICAL
    };

    static void init(Level log_level = Level::TRACE);

    ConsoleLog() = delete;
};

#define BTX_TRACE(fmt, ...)    SPDLOG_TRACE(fmt, __VA_ARGS__)
#define BTX_INFO(fmt, ...)     SPDLOG_INFO(fmt, __VA_ARGS__)
#define BTX_WARN(fmt, ...)     SPDLOG_WARN(fmt, __VA_ARGS__)
#define BTX_ERROR(fmt, ...)    SPDLOG_ERROR(fmt, __VA_ARGS__)
#define BTX_CRITICAL(fmt, ...) SPDLOG_CRITICAL(fmt, __VA_ARGS__); std::abort()

} // namespace btx

#endif // BRASSTACKS_LOG_CONSOLELOG_HPP