#include "LOG_SYSTEM_UTIL.h"
#include <chrono>
#include <ctime>
#include <iostream>

LogLevel LogSystem::current_level = LOG_INFO;
std::ofstream LogSystem::log_file;
std::string LogSystem::log_file_name;

void LogSystem::init_log_system(const std::string& file_name) {
    log_file_name = file_name;
    log_file.open(file_name, std::ios::app);
}

void LogSystem::set_log_level(LogLevel level) {
    current_level = level;
}

std::string get_time_str() {
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    return std::ctime(&now_time);
}

void LogSystem::log_debug(const std::string& msg) {
    if (current_level > LOG_DEBUG) return;
    std::string log = "[" + get_time_str() + "] [DEBUG] " + msg;
    log_file << log;
    std::cout << log;
}

void LogSystem::log_info(const std::string& msg) {
    if (current_level > LOG_INFO) return;
    std::string log = "[" + get_time_str() + "] [INFO] " + msg;
    log_file << log;
    std::cout << log;
}

void LogSystem::log_warn(const std::string& msg) {
    if (current_level > LOG_WARN) return;
    std::string log = "[" + get_time_str() + "] [WARN] " + msg;
    log_file << log;
    std::cout << log;
}

void LogSystem::log_error(const std::string& msg) {
    std::string log = "[" + get_time_str() + "] [ERROR] " + msg;
    log_file << log;
    std::cout << log;
}

void LogSystem::close_log() {
    if (log_file.is_open()) log_file.close();
}
