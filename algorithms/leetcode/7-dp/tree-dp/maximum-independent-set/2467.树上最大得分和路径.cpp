/*
 * @lc app=leetcode.cn id=2467 lang=cpp
 *
 * [2467] 树上最大得分和路径
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>> g(n);
        for(auto& e: edges) {
            int e0 = e[0];
            int e1 = e[1];
            g[e0].push_back(e1);
            g[e1].push_back(e0);
        }

        vector<int> bob_time(n, n);
        function<bool(int, int, int)> dfs_bob = [&] (int x, int fa, int t) -> bool {
            if(x == 0) {
                bob_time[x] = t;
                return true;
            }

            int v = amount[x];
            for(auto y: g[x]) {
                if( y  != fa && dfs_bob(y, x, t+1)) {
                    bob_time[x] = t;
                    return true;
                }
            }
            return false;
        };
        dfs_bob(bob, -1, 0);
        g[0].push_back(-1);
        int ans = INT_MIN;

        function<void(int, int, int, int)> dfs_alice = [&] (int x, int fa, int alice_time, int tot) {
            if(alice_time < bob_time[x]) {
                tot += amount[x];
            } else if(alice_time == bob_time[x]) {
                tot += amount[x] / 2;
            }
            if(g[x].size() == 1) {  // 叶子
                ans = max(ans, tot);
                return;
            }
            for(auto y: g[x]) {
                if(y != fa) {
                    dfs_alice(y, x, alice_time+1, tot);
                }
            }
        };
        dfs_alice(0, -1, 0, 0);
        return ans;


    }
};
// @lc code=end

