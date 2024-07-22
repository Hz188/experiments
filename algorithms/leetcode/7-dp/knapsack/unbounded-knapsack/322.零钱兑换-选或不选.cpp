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

        // 1. 记忆化搜索
        /*
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
        */
        // 2. 递推
        // vector<vector<int>> dp(n+1, vector<int>(amount+1, INT_MAX / 2));
        // dp[0][0] = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j <= amount; j++) {
        //         if(j >= coins[i])
        //             dp[i+1][j] = min(dp[i][j], dp[i+1][j-coins[i]]+1);
        //         else 
        //             dp[i+1][j] = dp[i][j];
        //     }
        // }
        // return dp[n][amount] < INT_MAX / 2 ? dp[n][amount] : -1;

        // 3. 空间优化 两个数组
        // vector<vector<int>> dp(2, vector<int>(amount+1, INT_MAX / 2));
        // dp[0][0] = 0;
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j <= amount; j++) {
        //         if(j >= coins[i])
        //             dp[(i+1) % 2][j] = min(dp[i % 2][j], dp[(i+1) % 2][j-coins[i]]+1);
        //         else 
        //             dp[(i+1) % 2][j] = dp[i % 2][j];
        //     }
        // }
        // return dp[n % 2][amount] < INT_MAX / 2 ? dp[n % 2][amount] : -1;

        // 4. 空间优化 一个数组
        vector<int> dp(amount+1, INT_MAX / 2);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j <= amount; j++) { // 这里和0-1背包有区别了，不需要反向
                if(j >= coins[i])
                    dp[j] = min(dp[j], dp[j-coins[i]]+1);
            }
        }
        return dp[amount] < INT_MAX / 2 ? dp[amount] : -1;
    }

};
// @lc code=end

