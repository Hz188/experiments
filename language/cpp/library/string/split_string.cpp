#include <string>
#include <iostream>
#include <sstream>
using namespace std;
int main() {
    stringstream ss("1,2,3,4");
    string item;
    while (getline(ss, item, ',')) {
        cout << item << endl;
    }
    return 0;
}