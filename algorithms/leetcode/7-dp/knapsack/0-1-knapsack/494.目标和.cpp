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
        /*
        p -> s - p
        p - (s - p) = t -> 2p - s = t
        p = (s + t) / 2
        */
        target += accumulate(nums.begin(), nums.end(), 0);
        if (target < 0 || target % 2) return 0;
        target /= 2;

        int n = nums.size();
        // 记忆化搜索
        // vector<vector<int>> cache(n, vector<int>(target+1, -1));
        // function<int(int, int)> dfs = [&](int i, int c) -> int {
        //     if (i < 0) return c == 0;
        //     int res = cache[i][c];
        //     if (res != -1) return res;
        //     if (c < nums[i]) return res = dfs(i - 1, c);
        //     return res = dfs(i - 1, c) + dfs(i - 1, c - nums[i]);
        // };
        // return dfs(n - 1, target);

        // 改递推 1:1 翻译
        // dfs(i, c) = dfs(i - 1, c) + dfs(i-1, c - w[i]) 
        // f[i][c] = f[i - 1][c] + f[i-1][c - w[i]]
        // i = -1 负数下标，通过索引偏移处理
        // f[i + 1][c] = f[i][c] + f[ijla[c - w[i]]]
        // vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        // dp[0][0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j <= target; j++) {
        //         if(j >= nums[i]) {
        //             dp[i+1][j] = dp[i][j] + dp[i][j-nums[i]];
        //         } else
        //             dp[i+1][j] = dp[i][j];
        //     }
        // }

        // 空间优化 两个数组
        // vector<vector<int>> dp(2, vector<int>(target+1, 0));
        // dp[0][0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j <= target; j++) {
        //         if(j >= nums[i]) {
        //             dp[(i+1) % 2][j] = dp[i%2][j] + dp[i%2][j-nums[i]];
        //         } else
        //             dp[(i+1) % 2][j] = dp[i%2][j];
        //     }
        // }
        // return dp[n%2][target];


        //空间优化 一个数组
        vector<int> dp(target+1, 0);
        dp[0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
        for(int i = 0; i < n; i++) {
            for(int j = target; j >= 0; j--) {
                if(j >= nums[i]) 
                    dp[j] = dp[j] + dp[j-nums[i]];
                // else
                    // dp[i+1][j] = dp[i][j];
            }
        }
        return dp[target];
    }

};
// @lc code=end

