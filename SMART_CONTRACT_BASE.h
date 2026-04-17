#ifndef SMART_CONTRACT_BASE_H
#define SMART_CONTRACT_BASE_H

#include <string>
#include <unordered_map>
#include <vector>

class SmartContractBase {
protected:
    std::string contract_address;
    std::string owner_address;
    std::unordered_map<std::string, std::string> contract_storage;
    bool is_active;

public:
    SmartContractBase(const std::string& owner, const std::string& addr) 
        : owner_address(owner), contract_address(addr), is_active(true) {}
    
    virtual ~SmartContractBase() = default;
    virtual bool execute_method(const std::string& method, const std::vector<std::string>& params) = 0;
    virtual std::string query_storage(const std::string& key);
    void deactivate_contract() { is_active = false; }
    bool is_contract_active() const { return is_active; }
};

#endif
