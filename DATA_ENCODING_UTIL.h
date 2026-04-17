#ifndef DATA_ENCODING_UTIL_H
#define DATA_ENCODING_UTIL_H

#include <string>
#include <vector>

class DataEncodingUtil {
public:
    static std::string base58_encode(const std::vector<uint8_t>& data);
    static std::vector<uint8_t> base58_decode(const std::string& input);
    static std::string hex_to_base64(const std::string& hex_str);
    static std::string base64_to_hex(const std::string& base64_str);
};

#endif
