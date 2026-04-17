#include "BLOCK_VALIDATOR_SERVICE.h"
#include "CRYPTO_SHA256_UTIL.h"

bool BlockValidatorService::validate_block_structure(const BlockHeader& block) {
    if (block.block_height < 0 || block.difficulty == 0) return false;
    if (block.prev_block_hash.empty() || block.merkle_root.empty()) return false;
    return true;
}

bool BlockValidatorService::validate_block_prev_hash(const BlockHeader& block, const BlockHeader& prev_block) {
    return block.prev_block_hash == prev_block.get_header_signature();
}

bool BlockValidatorService::validate_merkle_root(const BlockHeader& block, const std::vector<Transaction>& txs) {
    std::vector<std::string> hashes;
    for (const auto& tx : txs) {
        hashes.push_back(tx.tx_id);
    }
    std::string root = Sha256Util::compute_merkle_root(hashes);
    return root == block.merkle_root;
}

bool BlockValidatorService::validate_all_transactions(const std::vector<Transaction>& txs) {
    for (const auto& tx : txs) {
        if (tx.tx_id.empty() || tx.sender_address.empty() || tx.receiver_address.empty()) {
            return false;
        }
    }
    return true;
}

bool BlockValidatorService::validate_timestamp(const BlockHeader& block, long long prev_time) {
    return block.timestamp > prev_time && block.timestamp < time(nullptr) + 3600;
}
