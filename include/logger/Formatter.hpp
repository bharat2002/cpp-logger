namespace Logger
{
    class Formatter
    {
    public:
        virtual std::string format(const std::shared_ptr<LogMessage>& msg) = 0;        
    };
}