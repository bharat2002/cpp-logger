#include <logger/Logger.h>
namespace Logger
{
Logger::Logger(const std::string& name) : name(name) {}

void Logger::log(const std::string& message, LogLevel msgLevel)
{
    std::shared_ptr<LogMessage> logMsg = std::make_shared<LogMessage>(message, name, msgLevel);
    logMsg->setThreadId(std::hash<std::thread::id>{}(std::this_thread::get_id()));
    logMsg->setTimestamp(std::chrono::system_clock::now());
    std::string formattedMessage;
    {
        std::lock_guard<std::mutex> lock(formatterMutex);
        formattedMessage = formatter ? formatter->format(logMsg) : message;
    }
    std::lock_guard<std::mutex> lock(sinksMutex);
    for (const auto& sink : sinks) {
        sink->log(formattedMessage);
    }
}

void Logger::addSink(std::shared_ptr<Sink> sink) {
    std::lock_guard<std::mutex> lock(sinksMutex);
    sinks.push_back(sink);
}

void Logger::setFormatter(std::shared_ptr<Formatter> fmt) {
    std::lock_guard<std::mutex> lock(formatterMutex);
    formatter = fmt;
}
}
