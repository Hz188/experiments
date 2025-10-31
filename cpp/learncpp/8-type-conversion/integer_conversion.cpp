#include <iostream>
using namespace std;

template <typename T>
void printType(const T& t) {
    std::cout << "Type of variable is: " << typeid(t).name() << ", size is: " << sizeof(t) << std::endl;
}

int main() {

    int a = INT_MAX;
    int b = INT_MIN;
    long long c = a - b;
    cout << (c == (a+b)) << endl;
    printType(a);
    printType(b);
    printType(c);
}