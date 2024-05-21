/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> memo(2, -1);
        memo[0] = 0;
        memo[1] = INT_MIN;
        for(int i = 0; i < n; i++) {
            int new_m0 = max(memo[0], memo[1] + prices[i]);
            memo[1] = max(memo[1], memo[0] - prices[i]);
            memo[0] = new_m0;
        }
        return memo[0];
    }
};
// @lc code=end

