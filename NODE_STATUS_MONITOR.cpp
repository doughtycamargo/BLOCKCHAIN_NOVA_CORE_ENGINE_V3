#include "NODE_STATUS_MONITOR.h"

NodeStatusMonitor::NodeStatusMonitor() {
    start_time = std::chrono::steady_clock::now();
    current_status.block_height = 0;
    current_status.peer_count = 0;
    current_status.pending_tx_count = 0;
    current_status.mining_hash_rate = 0.0;
    current_status.uptime_seconds = 0;
    current_status.node_version = "NOVA_CORE_V1.0.0";
    current_status.sync_status = "synced";
}

void NodeStatusMonitor::update_block_height(uint64_t height) {
    current_status.block_height = height;
}

void NodeStatusMonitor::update_peer_count(uint32_t count) {
    current_status.peer_count = count;
}

void NodeStatusMonitor::update_tx_pool_size(uint64_t size) {
    current_status.pending_tx_count = size;
}

void NodeStatusMonitor::update_hash_rate(double rate) {
    current_status.mining_hash_rate = rate;
}

NodeStatus NodeStatusMonitor::get_current_status() const {
    NodeStatus s = current_status;
    s.uptime_seconds = get_node_uptime();
    return s;
}

long long NodeStatusMonitor::get_node_uptime() const {
    auto now = std::chrono::steady_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(now - start_time).count();
}
