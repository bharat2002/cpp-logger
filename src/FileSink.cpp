#include <logger/Logger.h>
#include <logger/Sink.hpp>
#include <logger/LogLevel.h>
#include <logger/LogMessage.hpp>
#include <logger/sinks/FileSink.h>
#include <fstream>
namespace Logger
{
    FileSink::FileSink(const std::string& filename) : filename(filename) {}
    void FileSink::log(const std::shared_ptr<LogMessage>& msg)
        {
            std::ofstream file(filename, std::ios::app);
            if (file.is_open()) {
                file << "[" << msg->getLoggerName() << "] "
                     << "[" << static_cast<int>(msg->getLevel()) << "] "
                     << msg->getMessage() << std::endl;
            }
        }
    }
