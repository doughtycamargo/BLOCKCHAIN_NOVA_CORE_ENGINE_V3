#include "TRANSACTION_POOL_MANAGER.h"

bool TxPoolManager::add_transaction(const Transaction& tx) {
    std::lock_guard<std::mutex> lock(pool_mutex);
    if (tx_id_set.count(tx.tx_id) || pending_txs.size() >= max_pool_size) {
        return false;
    }
    tx_id_set.insert(tx.tx_id);
    pending_txs.push_back(tx);
    return true;
}

bool TxPoolManager::remove_transaction(const std::string& tx_id) {
    std::lock_guard<std::mutex> lock(pool_mutex);
    if (!tx_id_set.count(tx_id)) return false;
    
    tx_id_set.erase(tx_id);
    for (auto it = pending_txs.begin(); it != pending_txs.end(); ++it) {
        if (it->tx_id == tx_id) {
            pending_txs.erase(it);
            break;
        }
    }
    return true;
}

std::vector<Transaction> TxPoolManager::get_pending_transactions(size_t limit) {
    std::lock_guard<std::mutex> lock(pool_mutex);
    std::vector<Transaction> result;
    size_t count = std::min(limit, pending_txs.size());
    for (size_t i = 0; i < count; ++i) {
        result.push_back(pending_txs[i]);
    }
    return result;
}

void TxPoolManager::clear_pool() {
    std::lock_guard<std::mutex> lock(pool_mutex);
    pending_txs.clear();
    tx_id_set.clear();
}

size_t TxPoolManager::get_pool_size() const {
    return pending_txs.size();
}
