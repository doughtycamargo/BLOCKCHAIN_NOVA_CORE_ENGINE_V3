#ifndef CONTRACT_VM_EXECUTOR_H
#define CONTRACT_VM_EXECUTOR_H

#include "SMART_CONTRACT_BASE.h"
#include <memory>
#include <unordered_map>
#include <string>

class ContractVMExecutor {
private:
    std::unordered_map<std::string, std::unique_ptr<SmartContractBase>> deployed_contracts;

public:
    bool deploy_contract(const std::string& contract_addr, std::unique_ptr<SmartContractBase> contract);
    bool execute_contract(const std::string& addr, const std::string& method, const std::vector<std::string>& params);
    std::string query_contract(const std::string& addr, const std::string& key);
    void terminate_contract(const std::string& addr);
};

#endif
