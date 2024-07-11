#include <vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> a{1, 2, 3};
    vector<int> b{1, 2, 3};
    vector<int> c{4, 5, 6};
    cout << (a == b) << endl;
    cout << (b == c) << endl;
}