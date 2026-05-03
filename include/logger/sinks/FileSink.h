#include <logger/Logger.h>
#include <logger/Sink.hpp>
#include <logger/LogLevel.h>
#include <logger/LogMessage.hpp>
#include <fstream>
namespace Logger
{
    class FileSink : public Sink
    {
    public:
        FileSink(const std::string& filename);

        void log(const std::string &message) override;

    private:
        std::string filename;
    };
}