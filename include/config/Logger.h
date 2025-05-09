#ifndef LOGGER_H_
#define LOGGER_H_

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <pthread.h>

#include "../enum/LogLevel.h"

class Logger {
    private:
        LogLevel appLogLevel = LogLevel::INFO;
        std::string trim(const std::string& str);
        std::type_info* typeInfo;
    
    public:
        Logger(std::type_info* type);
        ~Logger();
        void log(LogLevel level, const std::string& message);
};

#endif