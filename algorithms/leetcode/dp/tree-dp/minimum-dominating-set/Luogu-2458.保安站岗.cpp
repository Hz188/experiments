#include <iostream>
#include <functional>
#include <vector>
#include <tuple>
#include <climits>
using namespace std;

int main() {

    int n; 
    cin >> n;

    vector<vector<int>> g(n);
    vector<int> cost(n);
    for(int i = 0; i < n; i++) {
        int idx;
        cin >> idx;
        cin >> cost[idx-1];
        
        int m; 
        cin >> m;
        g[idx-1] = vector<int>(m);
        for(int j = 0; j < m; j++) {
            cin >> g[idx-1][j];
            g[idx-1][j]--;
        }
    }

    /*
    cout << "cost: " << endl;
    for(auto x : cost) {
        cout << x << ", ";
    }
    cout << endl;

    cout << "tree: " << endl;
    int i = 0;
    for(auto& child: g) {
        cout << i << ": ";
        i++;
        for(auto c: child) {
            cout << c << ", ";
        }
        cout << endl;
    }
    */

    function<tuple<int, int, int>(int)> dfs = [&] (int x) -> tuple<int, int, int> {
        int choose = cost[x], by_fa = 0, by_child = INT_MAX;
        
        for(auto y: g[x]) {
            auto [y_choose, y_by_fa, y_by_child] = dfs(y); // blue yellow red
            choose += min(y_choose, y_by_fa);
            by_fa += min(y_choose, y_by_child);
            by_child = min(by_child, y_choose - y_by_child);
        }
        // cout << choose << ", " << by_fa << ", " << by_child << endl;
        return {choose, by_fa, by_fa + max(0, by_child)};
    };
    vector<int> in_degree(n, 0);
    for(int i = 0; i < n; i++) {
        for(auto child: g[i]) {
            in_degree[child]++;
        }
    }
    int root = 0;
    for(int i = 0; i < n; i++) {
        if(in_degree[i] == 0){
            root = i;
            break;
        }
    }
    auto [choose, _, by_child] = dfs(root);
    cout << min(choose, by_child) << endl;
    return 0;
}