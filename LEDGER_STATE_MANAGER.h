#ifndef LEDGER_STATE_MANAGER_H
#define LEDGER_STATE_MANAGER_H

#include <unordered_map>
#include <string>
#include <mutex>
#include <cstdint>

class LedgerStateManager {
private:
    std::unordered_map<std::string, uint64_t> account_balances;
    std::mutex state_mutex;

public:
    uint64_t get_balance(const std::string& address);
    void set_balance(const std::string& address, uint64_t balance);
    bool transfer_balance(const std::string& from, const std::string& to, uint64_t amount, uint64_t fee);
    void create_genesis_account(const std::string& address, uint64_t initial_balance);
    void reset_state();
};

#endif
