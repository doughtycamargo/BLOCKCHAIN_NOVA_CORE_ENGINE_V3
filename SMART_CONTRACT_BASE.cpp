#include "SMART_CONTRACT_BASE.h"

std::string SmartContractBase::query_storage(const std::string& key) {
    auto it = contract_storage.find(key);
    if (it == contract_storage.end()) return "";
    return it->second;
}
