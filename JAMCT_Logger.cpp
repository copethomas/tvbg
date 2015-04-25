#include "JAMCT_Logger.h"
#include <iostream>
#include <string>
#include <sstream>
#include <thread>

bool JAMCT_Logger::Log(JAMCT_Logger::SeverityLevels messageLevel, std::string applicationSection, std::string message)
{
    std::string tmpLogMessage;
    tmpLogMessage = getDateTime() + " : [" + SeverityLevelsStrings[messageLevel] + "]" + " : [" + applicationSection + "] - " + message + "\n";
    try
    {
        JAMCT_Logger::logMessages.push_back(tmpLogMessage);
        return true;
    }
    catch(std::bad_alloc& errorMessage)
    {
        return false;
    }
}

std::string JAMCT_Logger::getDateTime()
{
    time_t rawtime;
    struct tm * timeinfo;
    char timeStringBuffer [80];
    time (&rawtime);
    timeinfo = localtime (&rawtime);
    strftime (timeStringBuffer,80,"%c",timeinfo);
    return std::string(timeStringBuffer);
}

 void JAMCT_Logger::loggingThread()
{
    while ((JAMCT_Logger::keepLogging) || (JAMCT_Logger::logMessages.size() != 0)) {
        if (JAMCT_Logger::LogFlushInterval != 0) {
            std::chrono::milliseconds dura( JAMCT_Logger::LogFlushInterval );
            std::this_thread::sleep_for( dura );
        }
        if (JAMCT_Logger::logMessages.size() != 0) {
          std::string toBeWritten = JAMCT_Logger::logMessages.front();
            std::cout << toBeWritten;
            JAMCT_Logger::logMessages.erase(JAMCT_Logger::logMessages.begin());
        }
    }
}

int JAMCT_Logger::GetWaitList()
{
    return JAMCT_Logger::logMessages.size();
}

JAMCT_Logger::JAMCT_Logger(int flushInterval): LogFlushInterval(flushInterval),keepLogging(true)
{
    JAMCT_Logger::Log(JAMCT_Logger::INFO,"JAMCT_Logger","JAMCT_Logger Starting...");
    std::thread flushThreadLauncher (&JAMCT_Logger::loggingThread,this);
    std::swap(flushThreadLauncher, flushThread);
}
bool JAMCT_Logger::Shutdown()
{
    JAMCT_Logger::Log(JAMCT_Logger::INFO,"JAMCT_Logger","JAMCT_Logger Shutting down...");
    JAMCT_Logger::keepLogging = false;
    try{
        JAMCT_Logger::flushThread.join();
        return true;
    }catch(std::exception& errorMessage) {
        return false;
    }
}

void JAMCT_Logger::Flush()
{
    while (JAMCT_Logger::logMessages.size() != 0);
}

std::string JAMCT_Logger::PointerToString(void *thePointer)
{
    std::stringstream conversion;
    conversion << thePointer;
    return conversion.str();
}


