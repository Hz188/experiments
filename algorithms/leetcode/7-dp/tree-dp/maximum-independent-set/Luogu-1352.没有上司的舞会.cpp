#include <iostream>
#include <functional>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> vals(n);
    for(auto& v: vals) {
        cin >> v;
    }
    vector<vector<int>> edges(n-1, vector<int>(2));
    for(auto& e: edges) {
        cin >> e[0] >> e[1];
    }

    vector<vector<int>> g(n);
    vector<int> in_degree(n, 0);
    for(auto& e: edges) {
        int child = e[0] - 1;
        int parent = e[1] - 1;
        in_degree[child]++;
        g[parent].push_back(child);
    }
    // for(int i = 0; i < n; i++) {
    //     cout << "parent: " << i << "\t";
    //     for(auto c: g[i]) {
    //         cout << c << ", ";
    //     }
    //     cout << endl;
    // }
    int root = 0;
    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0) {
            root = i;
            break;
        }
    }

    function<tuple<int, int>(int)> dfs = [&] (int x) -> tuple<int, int> {
        
        int in = vals[x], not_in = 0;

        for(auto c: g[x]) {
            auto [c_in, c_not_in] = dfs(c);
            in += c_not_in;
            not_in += max(c_in, c_not_in);
        }
        // cout << in << not_in << endl;
        return {in, not_in};
    };

    auto [root_in, root_not_in] = dfs(root);
    cout << max(root_in, root_not_in) << endl;
    return 0;

}