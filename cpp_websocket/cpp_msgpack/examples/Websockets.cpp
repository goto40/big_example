#include <seasocks/Server.h>
#include <seasocks/WebSocket.h>
#include <seasocks/PrintfLogger.h>
#include <memory>
#include <string>
#include <array>
#include <algorithm>
#include <nlohmann/json.hpp>

namespace data {
    struct Payload {
        std::string text;
        std::array<int,4> values;
    };

    void to_json(nlohmann::json& j, const Payload& p) {
        j = nlohmann::json{ {"text", p.text}, {"values", p.values} };
    }

    void from_json(const nlohmann::json& j, Payload& p) {
        j.at("text").get_to(p.text);
        j.at("values").get_to(p.values);
    }
}

data::Payload f(const data::Payload& input) {
    data::Payload p;
    p.text="result of: \""+input.text+"\"";
    std::transform(
        input.values.begin(),
        input.values.end(),
        p.values.begin(),
        [](auto x){ return x*x; }
    );
    p.values[0]=512;
    return p;
}

class MyHandler : public seasocks::WebSocket::Handler {
public:
    void onConnect(seasocks::WebSocket* /*connection*/) override {
        std::cout << "** connect\n";
    }

    void onData(seasocks::WebSocket* connection, const uint8_t* data, size_t length) override {
        std::cout << "** onData (bin)\n";

        auto deserialized = nlohmann::json::from_msgpack(data, data+length);
        std::cout << deserialized << "\n";

        data::Payload request = deserialized.get<data::Payload>();
        nlohmann::json response = f(request);

        auto serialized = nlohmann::json::to_msgpack(response);
        connection->send(serialized.data(), serialized.size()); // binary
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