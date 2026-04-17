#ifndef PEER_DISCOVERY_SERVICE_H
#define PEER_DISCOVERY_SERVICE_H

#include "P2P_NETWORK_NODE.h"
#include <vector>
#include <string>

class PeerDiscoveryService {
private:
    std::vector<std::string> bootstrap_nodes;
    P2PNetworkNode* local_node;

public:
    PeerDiscoveryService(P2PNetworkNode* node) : local_node(node) {}
    
    void init_bootstrap_list();
    void discover_peers_from_bootstrap();
    void broadcast_peer_list();
    void receive_peer_list(const std::string& peer_data);
    void clean_inactive_peers();
};

#endif
