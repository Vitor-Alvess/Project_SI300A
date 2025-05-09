#ifndef LOGLEVEL_H_
#define LOGLEVEL_H_

enum class LogLevel {
    ERROR,
    WARNING,
    INFO,
    DEBUG
};

std::string leveltoString(LogLevel level) {
    switch (level) {
        case LogLevel::ERROR: return "ERROR";
        case LogLevel::WARNING: return "WARNING";
        case LogLevel::INFO: return "INFO";
    }
}

LogLevel stringToLevel(const std::string& level) {
    if (level == "ERROR") return LogLevel::ERROR;
    else if (level == "WARNING") return LogLevel::WARNING;
    else if (level == "INFO") return LogLevel::INFO;
#endif