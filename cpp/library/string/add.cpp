#include <string>
#include <iostream>
using namespace std;
int main() {
    string a = "abc";
    auto b = a + "123";
    auto c = a + '1';
    cout << b << endl;
    cout << c << endl;
    return 0;
}