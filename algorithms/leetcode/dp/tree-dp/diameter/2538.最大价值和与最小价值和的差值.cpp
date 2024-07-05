/*
 * @lc app=leetcode.cn id=2538 lang=cpp
 *
 * [2538] 最大价值和与最小价值和的差值
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }

        long ans = 0;
        function<pair<long, long>(int, int)> dfs = [&](int x, int fa) -> pair<long, long> {
            // 返回：带上端点的最大路径和、不带端点的最大路径和
            long p = price[x], max_s1 = p, max_s2 = 0; // 叶子节点直接返回的值
            for (int y : g[x])  // 多叉树的dfs遍历
                if (y != fa) {
                    auto [s1, s2] = dfs(y, x);
                    // 前面最大带叶子的路径和 + 当前不带叶子的路径和
                    // 前面最大不带叶子的路径和 + 当前带叶子的路径和
                    ans = max(ans, max(max_s1 + s2, max_s2 + s1));  // 记录最大直径
                    // 记录最大 「链」
                    max_s1 = max(max_s1, s1 + p); 
                    max_s2 = max(max_s2, s2 + p); // 这里加上 p 是因为 x 必然不是叶子
                }
            return {max_s1, max_s2};  //叶子节点不会执行上面for的内容，直接返回for上方的初始值
        };
        dfs(0, -1);  //随便找个节点开始dfs就行，将根的单边路径最值转化为了树的最大直径问题
        return ans;
    }
};
// @lc code=end

