#pragma once
#include "Sink.hpp"
#include "LogLevel.h"
#include "LogMessage.hpp"
#include <vector>
#include <memory>
#include "Formatter.hpp"
#include <mutex>
#include <queue>
#include <condition_variable>
#include <thread>
#include <atomic>
namespace Logger
{
class Logger
{
    private:
    std::queue<std::shared_ptr<LogMessage>> logQueue;
    std::condition_variable logCondition;
    std::mutex logQueueMutex;
    std::thread workerThread;
    std::atomic<bool> running{true};
    std::string name;
    std::mutex sinksMutex;
    std::vector<std::shared_ptr<Sink>> sinks;
    void processLogs();
public:
    Logger(const std::string& name);
    void addSink(std::shared_ptr<Sink> sink);
    void log(const std::string& message, LogLevel msgLevel);
    ~Logger();
};

}