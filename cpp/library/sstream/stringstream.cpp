#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::stringstream ss;
    ss << "Hello, " << "world!" << 123;

    std::string result = ss.str();
    std::cout << result << std::endl; // 输出: Hello, world!123
    return 0;
}
