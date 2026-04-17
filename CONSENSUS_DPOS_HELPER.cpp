#include "CONSENSUS_DPOS_HELPER.h"
#include <algorithm>

void DPoSHelper::cast_vote(const std::string& voter, const std::string& candidate, uint64_t amount) {
    votes[candidate] += amount;
}

std::vector<std::string> DPoSHelper::elect_validators() {
    std::vector<std::pair<std::string, uint64_t>> sorted(votes.begin(), votes.end());
    std::sort(sorted.begin(), sorted.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    validators.clear();
    for (size_t i = 0; i < sorted.size() && i < max_validator_count; ++i) {
        validators.push_back(sorted[i].first);
    }
    return validators;
}

bool DPoSHelper::is_validator(const std::string& address) {
    for (const auto& v : validators) {
        if (v == address) return true;
    }
    return false;
}

void DPoSHelper::update_validator_list() {
    elect_validators();
}

uint64_t DPoSHelper::get_vote_count(const std::string& candidate) {
    auto it = votes.find(candidate);
    if (it == votes.end()) return 0;
    return it->second;
}
