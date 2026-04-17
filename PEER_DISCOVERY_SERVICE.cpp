#include "PEER_DISCOVERY_SERVICE.h"

void PeerDiscoveryService::init_bootstrap_list() {
    bootstrap_nodes.push_back("bootstrap1.nova-chain.com:8333");
    bootstrap_nodes.push_back("bootstrap2.nova-chain.com:8333");
    bootstrap_nodes.push_back("bootstrap3.nova-chain.com:8333");
}

void PeerDiscoveryService::discover_peers_from_bootstrap() {
    for (const auto& addr : bootstrap_nodes) {
        size_t pos = addr.find(':');
        std::string ip = addr.substr(0, pos);
        uint16_t port = std::stoi(addr.substr(pos + 1));
        
        PeerInfo peer;
        peer.ip_address = ip;
        peer.port = port;
        peer.connection_status = 1;
        local_node->connect_to_peer(peer);
    }
}

void PeerDiscoveryService::broadcast_peer_list() {
    auto peers = local_node->get_connected_peers();
    std::string data;
    for (const auto& p : peers) {
        data += p.ip_address + ":" + std::to_string(p.port) + ";";
    }
    local_node->broadcast_block(data);
}

void PeerDiscoveryService::receive_peer_list(const std::string& peer_data) {
    // Parse peer list and connect to new peers
}

void PeerDiscoveryService::clean_inactive_peers() {
    auto peers = local_node->get_connected_peers();
    for (const auto& p : peers) {
        if (p.connection_status == 0) {
            local_node->disconnect_peer(p.node_id);
        }
    }
}
