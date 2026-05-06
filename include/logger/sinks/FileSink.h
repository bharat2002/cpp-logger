#include <logger/Logger.h>
#include <logger/Sink.hpp>
#include <logger/LogLevel.h>
#include <logger/LogMessage.hpp>
#include <fstream>
#include <logger/formatters/PatternFormatter.hpp>
namespace Logger
{
    class FileSink : public Sink
    {
    public:
        FileSink(const std::string& filename, std::shared_ptr<Formatter> formatter = std::make_shared<PatternFormatter>(), LogLevel minLevel = LogLevel::TRACE);
        void write(const std::string &message) override;

    private:
        std::string filename;
    };
}