#include <logger/Logger.h>
namespace Logger
{

void Logger::processLogs() {
    while (running.load() || !logQueue.empty()) {

        std::unique_lock<std::mutex>
            lock(logQueueMutex);

        logCondition.wait(
            lock,
            [this] {
                return !logQueue.empty()
                       || !running.load();
            }
        );

        while (!logQueue.empty()) {
            std::shared_ptr<LogMessage> msg = logQueue.front();
            logQueue.pop();
            lock.unlock();
            std::string formatted = formatter->format(msg);
            for (auto& sink : sinks) {
                sink->log(formatted);
            }
            lock.lock();
        }
        
    }
}

Logger::Logger(const std::string& name) : name(name) {
    workerThread = std::thread(&Logger::processLogs, this);
}

void Logger::log(const std::string& message, LogLevel msgLevel)
{
    std::shared_ptr<LogMessage> logMsg = std::make_shared<LogMessage>(message, name, msgLevel);
    logMsg->setThreadId(std::hash<std::thread::id>{}(std::this_thread::get_id()));
    logMsg->setTimestamp(std::chrono::system_clock::now());
    {
        std::lock_guard<std::mutex> lock(logQueueMutex);
        logQueue.push(logMsg);
    }
    logCondition.notify_one();
}

void Logger::addSink(std::shared_ptr<Sink> sink) {
    std::lock_guard<std::mutex> lock(sinksMutex);
    sinks.push_back(sink);
}

void Logger::setFormatter(std::shared_ptr<Formatter> fmt) {
    std::lock_guard<std::mutex> lock(formatterMutex);
    formatter = fmt;
}
Logger::~Logger() {
    running.store(false);
    logCondition.notify_all();

    if (workerThread.joinable()) {
        workerThread.join();
    }
}
}
