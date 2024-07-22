/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    double frogPosition(int n, vector<vector<int>> &edges, int t, int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0}; // 减少额外判断的小技巧
        for (auto &e: edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x); // 建树
        }

        function<long long(int, int, int)> dfs = [&](int x, int fa, int left_t) -> long long {
            // t 秒后必须在 target（恰好到达，或者 target 是叶子停在原地）
            if (left_t == 0) return x == target;
            if (x == target) return g[x].size() == 1;
            for (int y: g[x]) { // 遍历 x 的儿子 y
                if (y != fa) { // y 不能是父节点
                    auto prod = dfs(y, x, left_t - 1); // 寻找 target
                    if (prod) return prod * (g[x].size() - 1); // 乘上儿子个数，并直接返回
                }
            }
            return 0; // 未找到 target
        };

        auto prod = dfs(1, 0, t);
        return prod ? 1.0 / prod : 0;
    }
};
// @lc code=end

