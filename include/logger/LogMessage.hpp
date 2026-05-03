#pragma once
#include <string>
#include <chrono>
#include <thread>
#include "LogLevel.h"

namespace Logger
{
    class LogMessage
    {
    public:
        LogMessage(const std::string& message, const std::string& loggerName, LogLevel level)
            : message(message), loggerName(loggerName), level(level) {}

        const std::string& getMessage() const { return message; }
        const std::string& getLoggerName() const { return loggerName; }
        std::chrono::system_clock::time_point getTimestamp() const { return timestamp; }
        void setTimestamp(const std::chrono::system_clock::time_point& ts) { timestamp = ts; }
        std::thread::id getThreadId() const { return threadId; }
        LogLevel getLevel() const { return level; }

    private:
        std::string message;
        std::string loggerName;
        std::chrono::system_clock::time_point timestamp;
        std::thread::id threadId;
        LogLevel level;
    };
}