#include "CONTRACT_VM_EXECUTOR.h"

bool ContractVMExecutor::deploy_contract(const std::string& contract_addr, std::unique_ptr<SmartContractBase> contract) {
    if (deployed_contracts.count(contract_addr)) return false;
    deployed_contracts[contract_addr] = std::move(contract);
    return true;
}

bool ContractVMExecutor::execute_contract(const std::string& addr, const std::string& method, const std::vector<std::string>& params) {
    auto it = deployed_contracts.find(addr);
    if (it == deployed_contracts.end() || !it->second->is_contract_active()) return false;
    return it->second->execute_method(method, params);
}

std::string ContractVMExecutor::query_contract(const std::string& addr, const std::string& key) {
    auto it = deployed_contracts.find(addr);
    if (it == deployed_contracts.end()) return "";
    return it->second->query_storage(key);
}

void ContractVMExecutor::terminate_contract(const std::string& addr) {
    auto it = deployed_contracts.find(addr);
    if (it != deployed_contracts.end()) {
        it->second->deactivate_contract();
    }
}
