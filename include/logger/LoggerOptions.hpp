#pragma once
namespace Logger
{
    class LoggerOptions
    {
    public:
        LoggerOptions()
        {
            // Default options can be set here
        } 
        virtual ~LoggerOptions() = default;       
    };

    class FileSinkOptions : public LoggerOptions
    {
        private:
        std::string filename;
    public:
        FileSinkOptions(const std::string& filename) : filename(filename) {}
        std::string getFilename() const { return filename; }
    };

    class ConsoleSinkOptions : public LoggerOptions
    {
      
    };
}