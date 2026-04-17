#ifndef NODE_CONFIG_MANAGER_H
#define NODE_CONFIG_MANAGER_H

#include <string>
#include <unordered_map>

class NodeConfigManager {
private:
    std::unordered_map<std::string, std::string> config_map;
    std::string config_file_path;

public:
    NodeConfigManager(const std::string& file_path) : config_file_path(file_path) {}
    
    bool load_config();
    bool save_config();
    std::string get_value(const std::string& key);
    void set_value(const std::string& key, const std::string& value);
    void init_default_config();
};

#endif
