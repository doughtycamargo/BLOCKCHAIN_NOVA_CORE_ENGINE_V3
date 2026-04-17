#include "BLOCK_HEADER_BASE.h"
#include <vector>
#include <string>
#include <mutex>
#include <iostream>

class BlockchainCore {
private:
    std::vector<BlockHeader> chain;
    std::mutex chain_mutex;
    uint64_t current_difficulty;

    std::string calculate_genesis_hash() {
        return "NOVA_GENESIS_BLOCK_HASH_000000001";
    }

public:
    BlockchainCore() : current_difficulty(4) {
        create_genesis_block();
    }

    void create_genesis_block() {
        BlockHeader genesis;
        genesis.block_height = 0;
        genesis.prev_block_hash = "00000000000000000000000000000000000000000000000";
        genesis.merkle_root = "GENESIS_MERKLE_ROOT";
        genesis.difficulty = current_difficulty;
        chain.push_back(genesis);
    }

    BlockHeader get_latest_block() const {
        return chain.back();
    }

    bool add_new_block(BlockHeader block) {
        std::lock_guard<std::mutex> lock(chain_mutex);
        if (block.prev_block_hash != get_latest_block().get_header_signature()) {
            return false;
        }
        chain.push_back(block);
        return true;
    }

    size_t get_chain_length() const {
        return chain.size();
    }
};
