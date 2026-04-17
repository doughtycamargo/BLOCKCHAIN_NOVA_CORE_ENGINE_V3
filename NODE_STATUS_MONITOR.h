#ifndef NODE_STATUS_MONITOR_H
#define NODE_STATUS_MONITOR_H

#include <cstdint>
#include <string>
#include <chrono>

struct NodeStatus {
    uint64_t block_height;
    uint32_t peer_count;
    uint64_t pending_tx_count;
    double mining_hash_rate;
    long long uptime_seconds;
    std::string node_version;
    std::string sync_status;
};

class NodeStatusMonitor {
private:
    NodeStatus current_status;
    std::chrono::steady_clock::time_point start_time;

public:
    NodeStatusMonitor();
    void update_block_height(uint64_t height);
    void update_peer_count(uint32_t count);
    void update_tx_pool_size(uint64_t size);
    void update_hash_rate(double rate);
    NodeStatus get_current_status() const;
    long long get_node_uptime() const;
};

#endif
