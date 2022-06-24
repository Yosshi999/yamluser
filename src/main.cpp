#include "yaml-cpp/yaml.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cout << "Usage: " << argv[0] << " " << "<yaml file>" << std::endl;
        return 0;
    }
    try {
        auto config = YAML::LoadFile(argv[1]);
        std::string user = config["user"]["name"].as<std::string>();
        int weight = config["user"]["weight"].as<int>();

        std::cout << "User: " << user << std::endl;
        std::cout << "Weight: " << weight << std::endl;
    } catch (YAML::Exception& e) {
        std::cerr << "YAML raised exception:" << std::endl;
        std::cerr << e.what() << std::endl;
    }

    return 0;
}