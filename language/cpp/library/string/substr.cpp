#include <string>
#include <iostream>
using namespace std;
int main() {
    string a = "abcde";
    auto b = a.substr(0, 2);
    auto c = a.substr(1, 3);
    cout << b << endl;
    cout << c << endl;

}