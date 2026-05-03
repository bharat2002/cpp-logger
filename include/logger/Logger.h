#pragma once
#include "Sink.hpp"
#include "LogLevel.h"
#include "LogMessage.hpp"
#include <vector>
#include <memory>
#include "Formatter.hpp"
#include <mutex>
namespace Logger
{
class Logger
{
    private:
    std::string name;
    std::mutex sinksMutex, formatterMutex;
    std::vector<std::shared_ptr<Sink>> sinks;
    std::shared_ptr<Formatter> formatter;
public:
    Logger(const std::string& name);
    void addSink(std::shared_ptr<Sink> sink);
    void setFormatter(std::shared_ptr<Formatter> fmt);
    void log(const std::string& message, LogLevel msgLevel);
};

}