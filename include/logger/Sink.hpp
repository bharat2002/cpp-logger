
#pragma once
#include <memory>
#include "LogMessage.hpp"
namespace Logger
{

class Sink {
public:
    virtual ~Sink() = default;

    virtual void log(const std::string& msg) = 0;
};

}