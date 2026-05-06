#pragma once

namespace Logger
{
    class ColorFormatter : public Formatter
    {
    public:
        ColorFormatter();
        std::string format(const std::shared_ptr<LogMessage>& message) override;
    };
}