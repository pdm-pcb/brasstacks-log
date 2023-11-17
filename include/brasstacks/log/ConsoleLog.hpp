#ifndef BRASSTACKS_LOG_CONSOLELOG_HPP
#define BRASSTACKS_LOG_CONSOLELOG_HPP

#include <string_view>
#include <string>
#include <chrono>
#include <list>
#include <mutex>

namespace btx {

class ConsoleLog {
public:
    static void trace(std::string_view const msg);
    static void info(std::string_view const msg);
    static void warn(std::string_view const msg);
    static void error(std::string_view const msg);

    static void dump();

    ConsoleLog() = delete;
    ~ConsoleLog() = delete;

    ConsoleLog(ConsoleLog &&) = delete;
    ConsoleLog(ConsoleLog const &) = delete;

    ConsoleLog & operator=(ConsoleLog &&) = delete;
    ConsoleLog & operator=(ConsoleLog const &) = delete;

private:
    using Clock = std::chrono::system_clock;
    using TimePoint = std::chrono::time_point<Clock>;
    using ClockRes = std::chrono::milliseconds;

    struct Message {
        TimePoint const ts;
        std::string const msg;
    };

    struct MessageBuffer {
        std::list<Message> list;
        std::mutex mutex;
    };

    static MessageBuffer _trace_buffer;
    static MessageBuffer _info_buffer;
    static MessageBuffer _warn_buffer;
    static MessageBuffer _error_buffer;

    struct Colors {
        static constexpr char red[]    = "\033[31m";
        static constexpr char green[]  = "\033[32m";
        static constexpr char yellow[] = "\033[33m";
        static constexpr char reset[]  = "\033[m";
    };

    static Message _format(char const *color, std::string_view const msg);
};

} // namespace btx

#endif // BRASSTACKS_LOG_CONSOLELOG_HPP