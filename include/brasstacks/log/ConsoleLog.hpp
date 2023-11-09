#ifndef BRASSTACKS_LOG_CONSOLELOG_HPP
#define BRASSTACKS_LOG_CONSOLELOG_HPP

#include <string_view>

namespace btx {

class ConsoleLog {
public:
    static void trace(std::string_view const msg);
    static void info(std::string_view const msg);
    static void warn(std::string_view const msg);
    static void error(std::string_view const msg);

    ConsoleLog() = delete;
    ~ConsoleLog() = delete;

    ConsoleLog(ConsoleLog &&) = delete;
    ConsoleLog(ConsoleLog const &) = delete;

    ConsoleLog & operator=(ConsoleLog &&) = delete;
    ConsoleLog & operator=(ConsoleLog const &) = delete;

private:
    struct Colors {
        static constexpr char red[]    = "\033[31m";
        static constexpr char green[]  = "\033[32m";
        static constexpr char yellow[] = "\033[33m";
        static constexpr char reset[]  = "\033[m";
    };

    static std::string _format(char const *color, std::string_view const msg);
};

} // namespace btx

#endif // BRASSTACKS_LOG_CONSOLELOG_HPP