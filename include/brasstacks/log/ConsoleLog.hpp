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

#define BTX_TRACE(...)    SPDLOG_TRACE(__VA_ARGS__)
#define BTX_INFO(...)     SPDLOG_INFO(__VA_ARGS__)
#define BTX_WARN(...)     SPDLOG_WARN(__VA_ARGS__)
#define BTX_ERROR(...)    SPDLOG_ERROR(__VA_ARGS__)
#define BTX_CRITICAL(...) SPDLOG_CRITICAL(__VA_ARGS__); std::abort()

} // namespace btx

#endif // BRASSTACKS_LOG_CONSOLELOG_HPP