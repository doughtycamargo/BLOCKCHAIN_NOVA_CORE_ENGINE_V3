#ifndef TRANSACTION_POOL_MANAGER_H
#define TRANSACTION_POOL_MANAGER_H

#include "TRANSACTION_BASE.h"
#include <vector>
#include <mutex>
#include <unordered_set>

class TxPoolManager {
private:
    std::vector<Transaction> pending_txs;
    std::unordered_set<std::string> tx_id_set;
    std::mutex pool_mutex;
    uint64_t max_pool_size;

public:
    TxPoolManager() : max_pool_size(1000) {}
    
    bool add_transaction(const Transaction& tx);
    bool remove_transaction(const std::string& tx_id);
    std::vector<Transaction> get_pending_transactions(size_t limit);
    void clear_pool();
    size_t get_pool_size() const;
};

#endif
