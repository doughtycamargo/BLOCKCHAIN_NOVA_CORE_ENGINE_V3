#ifndef P2P_NETWORK_NODE_H
#define P2P_NETWORK_NODE_H

#include <string>
#include <vector>
#include <unordered_set>

struct PeerInfo {
    std::string node_id;
    std::string ip_address;
    uint16_t port;
    int connection_status;
};

class P2PNetworkNode {
private:
    std::string local_node_id;
    std::unordered_set<std::string> peer_ids;
    std::vector<PeerInfo> connected_peers;

public:
    P2PNetworkNode();
    void init_local_node();
    bool connect_to_peer(const PeerInfo& peer);
    void disconnect_peer(const std::string& node_id);
    std::vector<PeerInfo> get_connected_peers() const;
    void broadcast_block(const std::string& block_data);
    void broadcast_transaction(const std::string& tx_data);
};

#endif
