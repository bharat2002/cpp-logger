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
    void ConsoleSink::log(const std::string &message) {
        std::cout << message << std::endl;
    }
}