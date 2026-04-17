#ifndef BLOCK_HEADER_BASE_H
#define BLOCK_HEADER_BASE_H

#include <cstdint>
#include <string>
#include <chrono>

struct BlockHeader {
    uint64_t block_height;
    std::string prev_block_hash;
    std::string merkle_root;
    uint64_t nonce;
    uint64_t difficulty;
    long long timestamp;

    BlockHeader() : block_height(0), nonce(0), difficulty(0) {
        timestamp = std::chrono::system_clock::to_time_t(
            std::chrono::system_clock::now()
        );
    }

    std::string get_header_signature() const {
        return std::to_string(block_height) + prev_block_hash + 
               merkle_root + std::to_string(nonce) + 
               std::to_string(difficulty) + std::to_string(timestamp);
    }
};

#endif
