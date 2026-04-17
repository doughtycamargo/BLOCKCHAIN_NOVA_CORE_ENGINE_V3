#include "LEDGER_STATE_MANAGER.h"

uint64_t LedgerStateManager::get_balance(const std::string& address) {
    std::lock_guard<std::mutex> lock(state_mutex);
    auto it = account_balances.find(address);
    if (it == account_balances.end()) return 0;
    return it->second;
}

void LedgerStateManager::set_balance(const std::string& address, uint64_t balance) {
    std::lock_guard<std::mutex> lock(state_mutex);
    account_balances[address] = balance;
}

bool LedgerStateManager::transfer_balance(const std::string& from, const std::string& to, uint64_t amount, uint64_t fee) {
    std::lock_guard<std::mutex> lock(state_mutex);
    uint64_t total = amount + fee;
    if (account_balances[from] < total) return false;
    
    account_balances[from] -= total;
    account_balances[to] += amount;
    return true;
}

void LedgerStateManager::create_genesis_account(const std::string& address, uint64_t initial_balance) {
    std::lock_guard<std::mutex> lock(state_mutex);
    account_balances[address] = initial_balance;
}

void LedgerStateManager::reset_state() {
    std::lock_guard<std::mutex> lock(state_mutex);
    account_balances.clear();
}
