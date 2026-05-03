#include <logger/Sink.hpp>
#include <logger/LogMessage.hpp>
#include <iostream>
#include <mutex>
namespace Logger
{
    class ConsoleSink : public Sink
    {
    private:
        std::mutex consoleMutex; 
    public:
        void log(const std::string &message) override;
    };
}