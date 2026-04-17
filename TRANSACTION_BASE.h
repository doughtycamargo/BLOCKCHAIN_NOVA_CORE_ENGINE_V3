#ifndef TRANSACTION_BASE_H
#define TRANSACTION_BASE_H

#include <string>
#include <cstdint>

struct Transaction {
    std::string tx_id;
    std::string sender_address;
    std::string receiver_address;
    uint64_t amount;
    uint64_t fee;
    long long timestamp;
    std::string signature;

    Transaction() : amount(0), fee(0), timestamp(0) {}
    
    std::string get_tx_sign_content() const {
        return sender_address + receiver_address + 
               std::to_string(amount) + std::to_string(fee) + 
               std::to_string(timestamp);
    }
};

#endif
