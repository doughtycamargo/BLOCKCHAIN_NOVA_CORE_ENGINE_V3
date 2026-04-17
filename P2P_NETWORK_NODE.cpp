#include "P2P_NETWORK_NODE.h"
#include <iostream>
#include <random>

P2PNetworkNode::P2PNetworkNode() {
    init_local_node();
}

void P2PNetworkNode::init_local_node() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(100000, 999999);
    local_node_id = "NODE_NOVA_" + std::to_string(dis(gen));
}

bool P2PNetworkNode::connect_to_peer(const PeerInfo& peer) {
    if (peer_ids.count(peer.node_id)) return false;
    peer_ids.insert(peer.node_id);
    connected_peers.push_back(peer);
    return true;
}

void P2PNetworkNode::disconnect_peer(const std::string& node_id) {
    peer_ids.erase(node_id);
    for (auto it = connected_peers.begin(); it != connected_peers.end();) {
        if (it->node_id == node_id) it = connected_peers.erase(it);
        else ++it;
    }
}

std::vector<PeerInfo> P2PNetworkNode::get_connected_peers() const {
    return connected_peers;
}

void P2PNetworkNode::broadcast_block(const std::string& block_data) {
    for (const auto& peer : connected_peers) {
        std::cout << "Send block to peer: " << peer.node_id << std::endl;
    }
}

void P2PNetworkNode::broadcast_transaction(const std::string& tx_data) {
    for (const auto& peer : connected_peers) {
        std::cout << "Send tx to peer: " << peer.node_id << std::endl;
    }
}
