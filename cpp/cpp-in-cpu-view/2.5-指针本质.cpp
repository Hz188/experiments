#include <iostream>
int main() {
    int a = 1;
    *(int*)(&a) = 2;
    std::cout << a << std::endl;
}