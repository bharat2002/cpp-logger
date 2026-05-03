#pragma once
#include <logger/Logger.h>
#include <logger/Sink.hpp>
#include <logger/LogLevel.h>
#include <logger/LogMessage.hpp>
#include "logger/sinks/ConsoleSink.h"
#include "logger/sinks/FileSink.h"
#include "logger/LoggerOptions.hpp"

namespace Logger
{

    enum class SinkType
    {
        CONSOLE,
        FILE
    };
    class SinkFactory
    {
    public:
        static std::shared_ptr<Sink> createSink(const SinkType& type,LoggerOptions& options) {
            switch (type) {
                case SinkType::CONSOLE:
                    return std::make_shared<ConsoleSink>();
                case SinkType::FILE:
                {
                    const FileSinkOptions& fileOptions = dynamic_cast<const FileSinkOptions&>(options);
                    return std::make_shared<FileSink>(fileOptions.getFilename());
                }
                default:
                    throw std::invalid_argument("Unknown sink type");
            }
        }
    };
}