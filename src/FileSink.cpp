#include <logger/Logger.h>
#include <logger/Sink.hpp>
#include <logger/LogLevel.h>
#include <logger/LogMessage.hpp>
#include <logger/sinks/FileSink.h>
#include <fstream>
namespace Logger
{
    FileSink::FileSink(const std::string& filename) : filename(filename) {}
    void FileSink::log(const std::string &message)
        {
            std::ofstream file(filename, std::ios::app);
            if (file.is_open()) {
                file << message << std::endl;
            }
        }
    }
