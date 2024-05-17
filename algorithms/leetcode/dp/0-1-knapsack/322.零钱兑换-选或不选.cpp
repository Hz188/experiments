/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> memo(n, vector<int>(amount+1, -1));
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0) return c == 0 ? 0 : INT_MAX / 2; // 除 2 是防止下面 + 1 溢出
            int &res = memo[i][c];
            if (res != -1) return res;
            if (c < coins[i]) return res = dfs(i - 1, c);
            return res = min(dfs(i - 1, c), dfs(i, c - coins[i]) + 1);
        };
        int ans = dfs(n - 1, amount);
        return ans < INT_MAX / 2 ? ans : -1;
    }
};
// @lc code=end

