#include "NODE_CONFIG_MANAGER.h"
#include <fstream>
#include <sstream>

bool NodeConfigManager::load_config() {
    std::ifstream file(config_file_path);
    if (!file.is_open()) return false;
    
    std::string line;
    while (std::getline(file, line)) {
        size_t pos = line.find('=');
        if (pos == std::string::npos) continue;
        std::string key = line.substr(0, pos);
        std::string val = line.substr(pos + 1);
        config_map[key] = val;
    }
    return true;
}

bool NodeConfigManager::save_config() {
    std::ofstream file(config_file_path);
    if (!file.is_open()) return false;
    
    for (const auto& pair : config_map) {
        file << pair.first << "=" << pair.second << "\n";
    }
    return true;
}

std::string NodeConfigManager::get_value(const std::string& key) {
    auto it = config_map.find(key);
    if (it == config_map.end()) return "";
    return it->second;
}

void NodeConfigManager::set_value(const std::string& key, const std::string& value) {
    config_map[key] = value;
}

void NodeConfigManager::init_default_config() {
    config_map["node_port"] = "8333";
    config_map["max_peers"] = "50";
    config_map["mining_enabled"] = "true";
    config_map["log_level"] = "info";
    config_map["storage_path"] = "./block_data";
}
