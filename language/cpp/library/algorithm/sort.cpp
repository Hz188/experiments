#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

void print_arr(int* a, int n) {
    for(int i = 0; i < n; i++){
        cout << a[i] << ", ";
    }
    cout << endl;
}
int main() {
    int a[3] = {1, 5, 3};
    sort(a, a+3);
    print_arr(a, 3);

    vector<int> b{1, 5, 3};
    sort(b.begin(), b.end());
    print_arr(b.data(), 3);

    pair<int, int> c[5] = {{1, 3}, {1, 2}, {3, 5}, {2, 4}, {3, 6}};
    sort(c, c+5);
    for(auto& x: c) {
        cout << x.first << ": " << x.second << endl;
    }
    return 0;
}