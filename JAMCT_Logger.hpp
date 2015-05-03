#ifndef JAMCT_LOGGER_H_INCLUDED
#define JAMCT_LOGGER_H_INCLUDED
#include <string>
#include <vector>
#include <thread>
#include <mutex>

class JAMCT_Logger {

private:
    const std::string SeverityLevelsStrings[8] = {"EMER", "AERT", "CRIT", "ERRO", "WARN", "NOTI", "INFO", "DEBU"};
    int LogFlushInterval;
    bool keepLogging;
    std::vector<std::string> logMessages;
    std::string getDateTime();
    std::thread flushThread;
    void loggingThread();
    std::mutex LogLock;

public:
    JAMCT_Logger(int flushInterval);
    bool EnableConsoleLogging(bool allToCout);
    bool EnableSysLogging(std::string applicationName, int facilityNumber);
    bool EnableFileLogging(std::string fullFilePath, bool appendToFile, bool createIfNotExsist);
    enum SeverityLevels {EMER, AERT, CRIT, ERRO, WARN, NOTI, INFO, DEBU};
    bool Log(JAMCT_Logger::SeverityLevels messageLevel, std::string applicationSection, std::string message);
    int GetWaitList();
    void Flush();
    bool Shutdown();
    std::string PointerToString(void *thePointer);

};


#endif // JAMCT_LOGGER_H_INCLUDED
