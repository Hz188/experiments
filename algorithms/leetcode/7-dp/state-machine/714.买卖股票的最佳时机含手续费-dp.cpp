/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n+1, vector<int>(2, -1));
        memo[0][0] = 0;
        memo[0][1] = INT_MIN;
        for(int i = 0; i < n; i++) {
            memo[i+1][0] = max(memo[i][0], memo[i][1] + prices[i]);
            memo[i+1][1] = max(memo[i][1], memo[i][0] - prices[i] - fee);
        }
        return memo[n][0];
    }
};
// @lc code=end

