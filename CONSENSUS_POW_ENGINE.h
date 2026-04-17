#ifndef CONSENSUS_POW_ENGINE_H
#define CONSENSUS_POW_ENGINE_H

#include "BLOCK_HEADER_BASE.h"
#include "CRYPTO_SHA256_UTIL.h"

class PoWEngine {
private:
    uint64_t base_difficulty;
    uint64_t adjust_interval;

public:
    PoWEngine() : base_difficulty(4), adjust_interval(10) {}
    
    BlockHeader mine_block(const BlockHeader& template_block);
    bool verify_block_consensus(const BlockHeader& block);
    uint64_t adjust_difficulty(uint64_t current_height, long long last_block_time);
};

#endif
