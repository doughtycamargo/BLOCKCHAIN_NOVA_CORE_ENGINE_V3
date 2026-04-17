#include "API_HTTP_SERVER_BASE.h"

void HttpAPIServer::register_route(const std::string& path, std::function<std::string(const std::string&)> handler) {
    routes[path] = handler;
}

bool HttpAPIServer::start_server() {
    if (is_running) return false;
    is_running = true;
    return true;
}

void HttpAPIServer::stop_server() {
    is_running = false;
}

std::string HttpAPIServer::handle_request(const std::string& path, const std::string& params) {
    auto it = routes.find(path);
    if (it == routes.end()) return "{\"error\":\"route not found\"}";
    return it->second(params);
}
