/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2) return 0;
        target /= 2;

        int n = nums.size();
        /* 记忆化搜索
        vector<vector<int>> cache(n, vector<int>(target+1, -1));
        function<int(int, int)> dfs = [&](int i, int c) -> int {
            if (i < 0) return c == 0;
            int res = cache[i][c];
            if (res != -1) return res;
            if (c < nums[i]) return res = dfs(i - 1, c);
            return res = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        };
        return dfs(n - 1, target);
        */
        // 改递推
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <= target; j++) {
                if(j >= nums[i-1]) {
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                } else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp[n][target];
    }

    // step1. 思考回溯怎么写 -> step2. 递归树，找重叠子问题，转记忆化搜索
    int zero_one_knapsack(int capacity, vector<int>& w, vector<int>& v) {
        int n = w.size();
        vector<vector<int>> memo(n+1, vector<int>(capacity + 1, -1));
        function<int(int, int)> dfs = [&](int i, int c) {
            if(i < 0) return 0;
            if(memo[i][c] != -1) return memo[i][c];
            if(c < w[i]) //只能不选 
                return memo[i][c] = dfs(i-1, c);
            return memo[i][c] = max(dfs(i-1, c), dfs(i-1, c-w[i]) + v[i]); //选
        };
        return dfs(n-1, capacity);
    };
};
// @lc code=end

