#include <logger/Logger.h>
namespace Logger
{
Logger::Logger(const std::string& name) : name(name) {}

void Logger::log(const std::string& message, LogLevel msgLevel)
{
    std::shared_ptr<LogMessage> logMsg = std::make_shared<LogMessage>(message, name, msgLevel);
    
    for (const auto& sink : sinks) {
        sink->log(formatter->format(logMsg));
    }
}

void Logger::addSink(std::shared_ptr<Sink> sink) {
    sinks.push_back(sink);
}

void Logger::setFormatter(std::shared_ptr<Formatter> fmt) {
    formatter = fmt;
}
}
