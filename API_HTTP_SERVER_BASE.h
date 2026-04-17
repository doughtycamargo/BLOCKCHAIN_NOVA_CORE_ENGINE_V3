#ifndef API_HTTP_SERVER_BASE_H
#define API_HTTP_SERVER_BASE_H

#include <string>
#include <functional>
#include <unordered_map>

class HttpAPIServer {
private:
    uint16_t port;
    bool is_running;
    std::unordered_map<std::string, std::function<std::string(const std::string&)>> routes;

public:
    HttpAPIServer(uint16_t listen_port) : port(listen_port), is_running(false) {}
    
    void register_route(const std::string& path, std::function<std::string(const std::string&)> handler);
    bool start_server();
    void stop_server();
    std::string handle_request(const std::string& path, const std::string& params);
};

#endif
