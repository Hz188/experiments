#include <iostream>
#include <sstream>
#include <string>
#include <list>

int main() {
    std::string data = "1,2,3,4,5";
    std::list<std::string> nodes;
    std::stringstream ss(data);
    std::string item;

    while (std::getline(ss, item, ',')) {
        nodes.push_back(item);
    }

    for (const auto& node : nodes) {
        std::cout << node << std::endl;
    }

    return 0;
}

/*
std::getline(std::istream& is, std::string& str, char delim);
*/