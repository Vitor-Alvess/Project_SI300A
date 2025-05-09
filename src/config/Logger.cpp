#include "../../include/config/Logger.h"

using namespace std;

Logger::Logger(type_info* typeInfo) {
    this->typeInfo = typeInfo;
    ifstream file("../resources/application.properties");
    string line, log_level;
    while (getline(file, line)) {
        if (line.find("LOG_LEVEL") != string::npos) { 
            size_t pos = line.find("=");
            if (pos != string::npos && pos + 1 < line.length()) log_level = trim(line.substr(pos + 1));
            else log_level = line.substr(pos + 1);

            appLogLevel = stringToLevel(log_level);
        }
    }
}

Logger::~Logger() {}

string Logger::trim(const string& str) {
    string result = str;

    size_t first = str.find_first_not_of(' ');
    if (first != string::npos) result.erase(0, first);
    
    size_t last = str.find_last_not_of(' ');
    if (last != string::npos) result.erase(last + 1);

    return result;
}

void Logger::log(LogLevel level, const string& message) {
    string finalmessage;

    time_t now = time(0);
    tm* localtm = localtime(&now);

    finalmessage += "[" + to_string(localtm->tm_hour) + ":" + to_string(localtm->tm_min) + ":" + to_string(localtm->tm_sec) + "] ";

    char buffer[25];
    pthread_getname_np(pthread_self(), buffer, sizeof(buffer));
    string current_threadname = buffer;

    finalmessage += "[" + current_threadname + "] - " + typeInfo->name() + " [" + leveltoString(level) + "] - " + message;

    switch (level) {
        case LogLevel::ERROR:
            finalmessage = "\033[1;31m" + finalmessage + "\033[0m"; 
            break;
        case LogLevel::WARNING:
            finalmessage = "\033[1;33m" + finalmessage + "\033[0m"; 
            break;
        case LogLevel::INFO:
            finalmessage = "\033[1;32m" + finalmessage + "\033[0m";
            break;
        case LogLevel::DEBUG:
            finalmessage = "\033[1;34m" + finalmessage + "\033[0m";
            break;
    };
    
    if (level <= appLogLevel) {
        cout << finalmessage << endl;
    }
}
        