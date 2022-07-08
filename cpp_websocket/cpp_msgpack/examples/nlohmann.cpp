#include <nlohmann/json.hpp>
#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

int main() {
  nlohmann::json j2 = {
        {"pi", 3.141},
        {"happy", true},
        {"name", "Niels"},
        {"nothing", nullptr},
        {"answer", {
            {"everything", 42}
        }},
        {"list", {1, 0, 2}},
        {"object", {
            {"currency", "USD"},
            {"value", 42.99}
        }}
    };
    
    std::cout << j2;

    static std::vector<std::uint8_t> bin = nlohmann::json::to_msgpack(j2);

    std::ofstream ofile("msg.bin", std::ios_base::binary);
    std::copy(
        bin.begin(),
        bin.end(),
        std::ostreambuf_iterator<char>(ofile)
    );
}