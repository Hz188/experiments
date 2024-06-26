/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=star#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> memo(n, {-1, -1});
        function<int(int, bool)> dfs = [&] (int i, bool hold) -> int {

            if (i < 0) {
                return hold ? INT_MIN / 2 : 0; // 防止溢出
            }
            int& res = memo[i][hold]; // 注意这里是引用
            if (res != -1) {
                return res; // 之前计算过
            }
            if (hold) {
                return res = max(dfs(i - 1, true), dfs(i - 1, false) - prices[i]);
            }
            return res = max(dfs(i - 1, false), dfs(i - 1, true) + prices[i] - fee);
        };
        return dfs(n-1, false);
        //超时
    }
};
// @lc code=end

