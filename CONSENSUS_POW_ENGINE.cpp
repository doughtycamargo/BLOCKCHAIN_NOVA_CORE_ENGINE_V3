#include "CONSENSUS_POW_ENGINE.h"
#include <random>

BlockHeader PoWEngine::mine_block(const BlockHeader& template_block) {
    BlockHeader mined = template_block;
    std::random_device rd;
    std::mt19937 gen(rd());
    
    while (true) {
        mined.nonce = gen();
        std::string hash = Sha256Util::compute_hash(mined.get_header_signature());
        if (Sha256Util::validate_pow(hash, mined.difficulty)) {
            break;
        }
    }
    return mined;
}

bool PoWEngine::verify_block_consensus(const BlockHeader& block) {
    std::string hash = Sha256Util::compute_hash(block.get_header_signature());
    return Sha256Util::validate_pow(hash, block.difficulty);
}

uint64_t PoWEngine::adjust_difficulty(uint64_t current_height, long long last_block_time) {
    if (current_height % adjust_interval != 0) return base_difficulty;
    long long elapsed = time(nullptr) - last_block_time;
    if (elapsed < 5) return base_difficulty + 1;
    if (elapsed > 20 && base_difficulty > 1) return base_difficulty - 1;
    return base_difficulty;
}
