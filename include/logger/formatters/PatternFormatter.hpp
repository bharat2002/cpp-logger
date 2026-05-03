namespace Logger
{
    class PatternFormatter : public Formatter
    {
    public:
        std::string format(const std::shared_ptr<LogMessage>& msg) override
        {
            return "[" + msg->getLoggerName() + "] "
                   + "[" + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(msg->getTimestamp().time_since_epoch()).count()) + "] " +
                   "[" + std::to_string(static_cast<int>(msg->getLevel())) + "] "
                   + "[" + msg->getMessage() + "]";
        }
    };
}