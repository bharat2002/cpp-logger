#pragma once
#include "Sink.hpp"
#include "LogLevel.h"
#include "LogMessage.hpp"
#include <vector>
#include <memory>
namespace Logger
{
class Logger
{
    private:
    std::string name;
    std::vector<std::shared_ptr<Sink>> sinks;
public:
    Logger(const std::string& name);
    void addSink(std::shared_ptr<Sink> sink);   
    void log(const std::string& message, LogLevel msgLevel);
};

}