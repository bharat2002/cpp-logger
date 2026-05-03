#include <logger/Sink.hpp>
#include <logger/LogMessage.hpp>
#include <iostream>
#include <mutex>
#include <logger/formatters/PatternFormatter.hpp>
namespace Logger
{
    class ConsoleSink : public Sink
    {
    private:
        std::mutex consoleMutex; 
    public:
        ConsoleSink(std::shared_ptr<Formatter> formatter = std::make_shared<PatternFormatter>(), LogLevel minLevel = LogLevel::TRACE);
        void write(const std::string &message) override;
    };
}