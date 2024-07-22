/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        // 1. 普通思路
        // int ans = 0;
        // int min_price = prices[0];
        // for (int p : prices) {
        //     ans = max(ans, p - min_price);
        //     min_price = min(min_price, p);
        // }
        // return ans;
        // 2. dp 思路
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
            dp[i][1] = max(dp[i - 1][1], -prices[i]); // 这里不是 dp[i-1][0] - prices[i] 是因为只有一次交易机会，我们只能买一次
        }
        return dp[n - 1][0];

    }
};
// @lc code=end

