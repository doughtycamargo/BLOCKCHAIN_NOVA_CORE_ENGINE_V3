#ifndef CONSENSUS_DPOS_HELPER_H
#define CONSENSUS_DPOS_HELPER_H

#include <vector>
#include <string>
#include <unordered_map>

class DPoSHelper {
private:
    std::vector<std::string> validators;
    std::unordered_map<std::string, uint64_t> votes;
    uint32_t max_validator_count;

public:
    DPoSHelper() : max_validator_count(21) {}
    
    void cast_vote(const std::string& voter, const std::string& candidate, uint64_t amount);
    std::vector<std::string> elect_validators();
    bool is_validator(const std::string& address);
    void update_validator_list();
    uint64_t get_vote_count(const std::string& candidate);
};

#endif
