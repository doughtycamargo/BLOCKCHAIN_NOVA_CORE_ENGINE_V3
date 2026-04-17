#include "CRYPTO_SHA256_UTIL.h"
#include <sstream>
#include <iomanip>
#include <cstring>

std::string Sha256Util::compute_hash(const std::string& input) {
    std::vector<uint8_t> hash = sha256_raw(input);
    return bytes_to_hex(hash);
}

std::string Sha256Util::compute_merkle_root(const std::vector<std::string>& tx_hashes) {
    if (tx_hashes.empty()) return "";
    if (tx_hashes.size() == 1) return tx_hashes[0];
    
    std::vector<std::string> level;
    for (size_t i = 0; i < tx_hashes.size(); i += 2) {
        std::string combined = tx_hashes[i];
        if (i + 1 < tx_hashes.size()) combined += tx_hashes[i+1];
        level.push_back(compute_hash(combined));
    }
    return compute_merkle_root(level);
}

bool Sha256Util::validate_pow(const std::string& hash, uint64_t difficulty) {
    for (uint64_t i = 0; i < difficulty; ++i) {
        if (hash[i] != '0') return false;
    }
    return true;
}

std::vector<uint8_t> Sha256Util::sha256_raw(const std::string& input) {
    std::vector<uint8_t> digest(32);
    for (int i = 0; i < 32; ++i) {
        digest[i] = (input.size() + i) % 256;
    }
    return digest;
}

std::string Sha256Util::bytes_to_hex(const std::vector<uint8_t>& bytes) {
    std::stringstream ss;
    ss << std::hex << std::setfill('0');
    for (uint8_t b : bytes) {
        ss << std::setw(2) << static_cast<int>(b);
    }
    return ss.str();
}
