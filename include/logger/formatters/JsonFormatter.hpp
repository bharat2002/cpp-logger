namespace Logger
{
    class JsonFormatter : public Formatter
    {
    public:
        std::string format(const std::shared_ptr<LogMessage>& msg) override
        {
            return "{ \"logger\": \"" + msg->getLoggerName() + "\", "
                   "\"level\": " + logLevelToString(msg->getLevel()) + ", "
                   "\"message\": \"" + msg->getMessage() + "\","+
                   "\"threadId\": \"" + std::to_string(msg->getThreadId()) + "\", " +
                   "\"timestamp\": \"" + std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(msg->getTimestamp().time_since_epoch()).count()) + "\" }";
                   
        }
    };
}