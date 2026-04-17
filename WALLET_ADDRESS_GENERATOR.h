#ifndef WALLET_ADDRESS_GENERATOR_H
#define WALLET_ADDRESS_GENERATOR_H

#include <string>
#include <utility>

class WalletAddressGenerator {
public:
    static std::pair<std::string, std::string> generate_key_pair();
    static std::string generate_address_from_public_key(const std::string& pub_key);
    static std::string sign_message(const std::string& message, const std::string& private_key);
    static bool verify_signature(const std::string& message, const std::string& signature, const std::string& pub_key);
};

#endif
