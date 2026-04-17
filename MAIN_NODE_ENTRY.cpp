#include "BLOCK_CHAIN_CORE.h"
#include "P2P_NETWORK_NODE.h"
#include "NODE_CONFIG_MANAGER.h"
#include "LOG_SYSTEM_UTIL.h"
#include "NODE_STATUS_MONITOR.h"
#include <iostream>

int main() {
    LogSystem::init_log_system("nova_node.log");
    LogSystem::log_info("Nova Blockchain Node Starting...");

    NodeConfigManager config("node.config");
    config.init_default_config();
    config.save_config();

    BlockchainCore core;
    P2PNetworkNode p2p_node;
    NodeStatusMonitor monitor;

    LogSystem::log_info("Genesis block created successfully");
    LogSystem::log_info("Node initialized, height: " + std::to_string(core.get_chain_length()));

    while (true) {
        NodeStatus status = monitor.get_current_status();
        LogSystem::log_info("Status: Height=" + std::to_string(status.block_height) + 
                          " Peers=" + std::to_string(status.peer_count));
        std::this_thread::sleep_for(std::chrono::seconds(5));
    }

    LogSystem::close_log();
    return 0;
}
