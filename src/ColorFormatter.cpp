#include <string>
#include <logger/LogMessage.hpp>
#include <logger/Formatter.hpp>
#include <logger/LogLevelUtils.hpp>
#include <logger/formatters/ColorFormatter.hpp>

namespace Logger
{
    ColorFormatter::ColorFormatter() {}

    std::string ColorFormatter::format(const std::shared_ptr<LogMessage>& message)
    {
        std::string colorCode;
        switch (message->getLevel()) {
            case LogLevel::TRACE: colorCode = "\033[37m"; break; // White
            case LogLevel::DEBUG: colorCode = "\033[36m"; break; // Cyan
            case LogLevel::INFO:  colorCode = "\033[32m"; break; // Green
            case LogLevel::WARN:  colorCode = "\033[33m"; break; // Yellow
            case LogLevel::ERROR: colorCode = "\033[31m"; break; // Red
            case LogLevel::FATAL: colorCode = "\033[35m"; break; // Magenta
            default:             colorCode = "\033[0m";  break; // Reset
        }

        std::time_t time = std::chrono::system_clock::to_time_t(message->getTimestamp());
        char timeStr[20];
        std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&time));

        return colorCode + "[" + message->getLoggerName() + "] "
               + "[" + timeStr + "] " +
               + "[" + std::to_string(message->getThreadId()) + "] " +
               "[" + logLevelToString(message->getLevel()) + "] "
               + "[" + message->getMessage() + "]\033[0m";
    }
}