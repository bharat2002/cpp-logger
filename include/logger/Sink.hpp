
#pragma once
#include <memory>
#include "LogMessage.hpp"
#include <logger/Formatter.hpp>
namespace Logger
{

class Sink {
    private:
    std::shared_ptr<Formatter> formatter_;
    LogLevel minLevel_;
    
public:
    Sink(std::shared_ptr<Formatter> formatter, LogLevel minLevel)
        : formatter_(formatter),
          minLevel_(minLevel)
    {}
    virtual void write(const std::string& msg)=0;

    virtual ~Sink() = default;
    
    virtual void log(const std::shared_ptr<LogMessage>& msg)
    {
        if (msg->getLevel() < minLevel_) {
            return;
        }
        std::string formatted = formatter_->format(msg);
        write(formatted);
    }
};

}