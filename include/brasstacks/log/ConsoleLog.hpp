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

    static void init(Level log_level);

    template<typename ...T>
    static void trace(std::format_string<T...> fmt, T&& ...args) {
        spdlog::trace(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void info(std::format_string<T...> fmt, T&& ...args) {
        spdlog::info(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void warn(std::format_string<T...> fmt, T&& ...args) {
        spdlog::warn(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void error(std::format_string<T...> fmt, T&& ...args) {
        spdlog::error(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void critical(std::format_string<T...> fmt, T&& ...args) {
        spdlog::critical(fmt, std::forward<T>(args)...);
        std::abort();
    }

    ConsoleLog() = delete;
};

} // namespace btx

#endif // BRASSTACKS_LOG_CONSOLELOG_HPP