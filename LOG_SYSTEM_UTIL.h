#ifndef LOG_SYSTEM_UTIL_H
#define LOG_SYSTEM_UTIL_H

#include <string>
#include <fstream>

enum LogLevel {
    LOG_DEBUG,
    LOG_INFO,
    LOG_WARN,
    LOG_ERROR
};

class LogSystem {
private:
    static LogLevel current_level;
    static std::ofstream log_file;
    static std::string log_file_name;

public:
    static void init_log_system(const std::string& file_name);
    static void set_log_level(LogLevel level);
    static void log_debug(const std::string& msg);
    static void log_info(const std::string& msg);
    static void log_warn(const std::string& msg);
    static void log_error(const std::string& msg);
    static void close_log();
};

#endif
