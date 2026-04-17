#ifndef BLOCK_VALIDATOR_SERVICE_H
#define BLOCK_VALIDATOR_SERVICE_H

#include "BLOCK_HEADER_BASE.h"
#include "TRANSACTION_BASE.h"
#include <vector>

class BlockValidatorService {
public:
    static bool validate_block_structure(const BlockHeader& block);
    static bool validate_block_prev_hash(const BlockHeader& block, const BlockHeader& prev_block);
    static bool validate_merkle_root(const BlockHeader& block, const std::vector<Transaction>& txs);
    static bool validate_all_transactions(const std::vector<Transaction>& txs);
    static bool validate_timestamp(const BlockHeader& block, long long prev_time);
};

#endif
