#include <logger/Logger.h>
#include <logger/Sink.hpp>
#include <logger/LogLevel.h>
#include <logger/LogMessage.hpp>
#include <logger/sinks/FileSink.h>
#include <fstream>
namespace Logger
{
    FileSink::FileSink(const std::string& filename, std::shared_ptr<Formatter> formatter, LogLevel minLevel) :  Sink(formatter, minLevel),filename(filename) {}
    void FileSink::write(const std::string &message)
        {
            std::ofstream file(filename, std::ios::app);
            if (file.is_open()) {
                file << message << std::endl;
            }
        }
    }
