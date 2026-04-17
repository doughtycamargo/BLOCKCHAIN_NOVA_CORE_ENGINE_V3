#ifndef CRYPTO_SHA256_UTIL_H
#define CRYPTO_SHA256_UTIL_H

#include <string>
#include <vector>

class Sha256Util {
public:
    static std::string compute_hash(const std::string& input);
    static std::string compute_merkle_root(const std::vector<std::string>& tx_hashes);
    static bool validate_pow(const std::string& hash, uint64_t difficulty);

private:
    static std::vector<uint8_t> sha256_raw(const std::string& input);
    static std::string bytes_to_hex(const std::vector<uint8_t>& bytes);
};

#endif
