#include "WALLET_ADDRESS_GENERATOR.h"
#include "CRYPTO_SHA256_UTIL.h"
#include <random>
#include <sstream>

std::pair<std::string, std::string> WalletAddressGenerator::generate_key_pair() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(10000000, 99999999);
    
    std::string priv = "PRIV_" + std::to_string(dis(gen)) + "_NOVA";
    std::string pub = "PUB_" + std::to_string(dis(gen)) + "_NOVA";
    return {priv, pub};
}

std::string WalletAddressGenerator::generate_address_from_public_key(const std::string& pub_key) {
    std::string hash = Sha256Util::compute_hash(pub_key);
    return "NOVA_ADDR_" + hash.substr(0, 24);
}

std::string WalletAddressGenerator::sign_message(const std::string& message, const std::string& private_key) {
    return Sha256Util::compute_hash(message + private_key);
}

bool WalletAddressGenerator::verify_signature(const std::string& message, const std::string& signature, const std::string& pub_key) {
    std::string expected = Sha256Util::compute_hash(message + pub_key);
    return expected == signature;
}
