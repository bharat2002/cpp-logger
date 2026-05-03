#include <logger/Sink.hpp>
#include <logger/LogMessage.hpp>
#include <iostream>

namespace Logger
{
    class ConsoleSink : public Sink
    {
    public:
        void log(const std::string &message) override;
    };
}