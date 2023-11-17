#include "brasstacks/log/ConsoleLog.hpp"

#include <format>
#include <algorithm>
#include <cstdio>

namespace btx {

ConsoleLog::MessageBuffer ConsoleLog::_trace_buffer { };
ConsoleLog::MessageBuffer ConsoleLog::_info_buffer  { };
ConsoleLog::MessageBuffer ConsoleLog::_warn_buffer  { };
ConsoleLog::MessageBuffer ConsoleLog::_error_buffer { };

// =============================================================================
void ConsoleLog::trace(std::string_view const msg) {
    auto const message = _format(Colors::reset, msg);

    std::unique_lock const lock(_trace_buffer.mutex);
    _trace_buffer.list.push_back(message);
}

// =============================================================================
void ConsoleLog::info(std::string_view const msg) {
    auto const message = _format(Colors::green, msg);

    std::unique_lock const lock(_info_buffer.mutex);
    _info_buffer.list.push_back(message);
}

// =============================================================================
void ConsoleLog::warn(std::string_view const msg) {
    auto const message = _format(Colors::yellow, msg);

    std::unique_lock const lock(_warn_buffer.mutex);
    _warn_buffer.list.push_back(message);
}

// =============================================================================
void ConsoleLog::error(std::string_view const msg) {
    auto const message = _format(Colors::red, msg);

    std::unique_lock const lock(_error_buffer.mutex);
    _error_buffer.list.push_back(message);
}

// =============================================================================
void ConsoleLog::dump() {
    static std::list<Message> messages;

    {
        std::unique_lock const lock(_trace_buffer.mutex);
        std::move(
            _trace_buffer.list.begin(),
            _trace_buffer.list.end(),
            std::back_inserter(messages)
        );
        _trace_buffer.list.clear();
    }

    {
        std::unique_lock const lock(_info_buffer.mutex);
        std::move(
            _info_buffer.list.begin(),
            _info_buffer.list.end(),
            std::back_inserter(messages)
        );
        _info_buffer.list.clear();
    }

    {
        std::unique_lock const lock(_warn_buffer.mutex);
        std::move(
            _warn_buffer.list.begin(),
            _warn_buffer.list.end(),
            std::back_inserter(messages)
        );
        _warn_buffer.list.clear();
    }

    {
        std::unique_lock const lock(_error_buffer.mutex);
        std::move(
            _error_buffer.list.begin(),
            _error_buffer.list.end(),
            std::back_inserter(messages)
        );
        _error_buffer.list.clear();
    }

    messages.sort(
        [](Message const &a, Message const &b) {
            return a.ts < b.ts;
        }
    );

    while(!messages.empty()) {
        std::fprintf(stderr, "%s\n", messages.front().msg.c_str());
        messages.pop_front();
    }
}

// =============================================================================
ConsoleLog::Message ConsoleLog::_format(char const *color,
                                        std::string_view const msg)
{
    static auto const *tz = std::chrono::current_zone();
    auto const now = Clock::now();

    return Message {
        .ts = now,
        .msg = std::format(
            "{:s}[{:%H:%M:%S}] {:s}{:s}",
            color,
            tz->to_local(std::chrono::time_point_cast<ClockRes>(now)),
            msg,
            Colors::reset
        )
    };
}

} // namespace btx