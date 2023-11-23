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

    static void init();
    static void set_level(Level log_level);

    ConsoleLog() = delete;
};

} // namespace btx

#define BTX_TRACE(...)    btx::ConsoleLog::init(); SPDLOG_TRACE(__VA_ARGS__)
#define BTX_INFO(...)     btx::ConsoleLog::init(); SPDLOG_INFO(__VA_ARGS__)
#define BTX_WARN(...)     btx::ConsoleLog::init(); SPDLOG_WARN(__VA_ARGS__)
#define BTX_ERROR(...)    btx::ConsoleLog::init(); SPDLOG_ERROR(__VA_ARGS__)
#define BTX_CRITICAL(...) btx::ConsoleLog::init(); SPDLOG_CRITICAL(__VA_ARGS__); std::abort()

#endif // BRASSTACKS_LOG_CONSOLELOG_HPP