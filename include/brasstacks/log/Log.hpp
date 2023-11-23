#ifndef BRASSTACKS_LOG_LOG_HPP
#define BRASSTACKS_LOG_LOG_HPP

#include <cstdlib>
#include <format>
#include <spdlog/spdlog.h>

namespace btx {

class Log final {
public:
    enum class Level : uint8_t {
        TRACE,
        INFO,
        WARN,
        ERROR,
        CRITICAL
    };

    static void set_level(Level log_level);

    template<typename ...T>
    static void trace(std::format_string<T...> fmt, T&& ...args) {
        _init();
        spdlog::trace(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void info(std::format_string<T...> fmt, T&& ...args) {
        _init();
        spdlog::info(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void warn(std::format_string<T...> fmt, T&& ...args) {
        _init();
        spdlog::warn(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void error(std::format_string<T...> fmt, T&& ...args) {
        _init();
        spdlog::error(fmt, std::forward<T>(args)...);
    }

    template<typename ...T>
    static void critical(std::format_string<T...> fmt, T&& ...args) {
        _init();
        spdlog::critical(fmt, std::forward<T>(args)...);
        std::abort();
    }

    Log() = delete;

private:
    static void _init();
};

} // namespace btx

#endif // BRASSTACKS_LOG_LOG_HPP