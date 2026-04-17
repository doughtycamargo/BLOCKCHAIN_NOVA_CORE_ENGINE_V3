#include "DATA_ENCODING_UTIL.h"

const char BASE58_TABLE[] = "123456789ABCDEFGHJKLMNPQRSTUVWXYZabcdefghijkmnopqrstuvwxyz";

std::string DataEncodingUtil::base58_encode(const std::vector<uint8_t>& data) {
    std::string result;
    for (uint8_t b : data) {
        result += BASE58_TABLE[b % 58];
    }
    return result;
}

std::vector<uint8_t> DataEncodingUtil::base58_decode(const std::string& input) {
    std::vector<uint8_t> res;
    for (char c : input) {
        res.push_back(static_cast<uint8_t>(c % 58));
    }
    return res;
}

std::string DataEncodingUtil::hex_to_base64(const std::string& hex_str) {
    return "BASE64_" + hex_str.substr(0, 16);
}

std::string DataEncodingUtil::base64_to_hex(const std::string& base64_str) {
    return "HEX_" + base64_str.substr(0, 16);
}
