/*
ConsoleSink.cpp
Created by: bharat2002
Created on: 2024-06-15
*/
#include <logger/Sink.hpp>
#include <logger/LogMessage.hpp>
#include <iostream>
#include <logger/sinks/ConsoleSink.h>
namespace Logger
{
    void ConsoleSink::log(const std::shared_ptr<LogMessage>& msg) {
        std::cout << "[" << msg->getLoggerName() << "] "
                  << "[" << static_cast<int>(msg->getLevel()) << "] "
                  << msg->getMessage() << std::endl;
    }
}