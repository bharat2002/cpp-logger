namespace Logger
{
    class PatternFormatter : public Formatter
    {
    public:
        std::string format(const std::shared_ptr<LogMessage>& msg) override
        {
            std::time_t time = std::chrono::system_clock::to_time_t(msg->getTimestamp());
            char timeStr[20];
            std::strftime(timeStr, sizeof(timeStr), "%Y-%m-%d %H:%M:%S", std::localtime(&time));

            return "[" + msg->getLoggerName() + "] "
                   + "[" + timeStr + "] " +
                   + "[" + std::to_string(msg->getThreadId()) + "] " +
                   "[" + logLevelToString(msg->getLevel()) + "] "
                   + "[" + msg->getMessage() + "]";
        }
    };
}