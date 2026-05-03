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
    ConsoleSink::ConsoleSink(std::shared_ptr<Formatter> formatter, LogLevel minLevel) : Sink(formatter, minLevel) {}
    void ConsoleSink::write(const std::string &message) {
        std::lock_guard<std::mutex> lock(consoleMutex);
        std::cout << message << std::endl;
    }
}