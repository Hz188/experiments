/*
 * @lc app=leetcode.cn id=714 lang=cpp
 *
 * [714] 买卖股票的最佳时机含手续费
 */

// @lc code=star#include <vector>
#include <functional>
using namespace std;
class Solution {
    vector<array<int, 2>> memo;

    int dfs(int i, bool hold, vector<int>& prices, int fee) {
        if (i < 0) {
            return hold ? INT_MIN / 2 : 0; // 防止溢出
        }
        int& res = memo[i][hold]; // 注意这里是引用
        if (res != -1) {
            return res; // 之前计算过
        }
        if (hold) {
            return res = max(dfs(i - 1, true, prices, fee), dfs(i - 1, false, prices, fee) - prices[i]);
        }
        return res = max(dfs(i - 1, false, prices, fee), dfs(i - 1, true, prices, fee) + prices[i] - fee);
    };

public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        memo.resize(n, {-1, -1}); // -1 表示还没有计算过
        return dfs(n - 1, false, prices, fee);
    }
};


// @lc code=end

