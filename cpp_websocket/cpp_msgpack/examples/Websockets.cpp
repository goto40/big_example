#include <seasocks/Server.h>
#include <seasocks/WebSocket.h>
#include <seasocks/PrintfLogger.h>
#include <memory>
#include <nlohmann/json.hpp>


class MyHandler : public seasocks::WebSocket::Handler {
public:
    void onConnect(seasocks::WebSocket* /*connection*/) override {
        std::cout << "** connect\n";
    }

    void onData(seasocks::WebSocket* connection, const uint8_t* data, size_t length) override {
        std::cout << "** onData (bin)\n";

        auto deserialized = nlohmann::json::from_msgpack(data, data+length);
        std::cout << deserialized << "\n";

        //msgpack::type::
        connection->send(data, length); // binary
    }

    void onData(seasocks::WebSocket* connection, const char* data) override {
        std::cerr << "*** error: only binary data allowed!\n";
        connection->send("error: only binary data allowed!");
    }

    void onDisconnect(seasocks::WebSocket* /*connection*/) override {
    }
};

int main() {
    auto logger = std::make_shared<seasocks::PrintfLogger>();
    seasocks::Server server(logger);

    auto handler = std::make_shared<MyHandler>();
    server.addWebSocketHandler("/", handler);
    
    server.serve("web", 9090);
}