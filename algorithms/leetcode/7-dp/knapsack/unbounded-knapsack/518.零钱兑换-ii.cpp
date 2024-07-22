/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
// 这题相当于是：方案数，322相当于是：最小价值
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0) return c == 0 ? 1 : 0; // 除 2 是防止下面 + 1 溢出
            int &res = memo[i][c];
            if (res != -1) return res;
            if (coins[i] > c) return res = dfs(i - 1, c);
            return res = dfs(i - 1, c) +  dfs(i, c - coins[i]);
        };
        return dfs(n-1, amount);
    }
};
// @lc code=end

