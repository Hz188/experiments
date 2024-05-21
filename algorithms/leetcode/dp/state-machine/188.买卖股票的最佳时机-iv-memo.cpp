/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(k+1, {-1,-1}));// -1 表示还没有计算过
        function<int(int, int, bool)> dfs = [&](int i, int j, bool hold) -> int {
            if (j < 0) return INT_MIN / 2; // 防止溢出
            if (i < 0) return hold ? INT_MIN / 2 : 0;
            int &res = memo[i][j][hold]; // 注意这里是引用
            if (res != -1) return res; // 之前计算过
            if (hold) return res = max(dfs(i - 1, j, true), dfs(i - 1, j - 1, false) - prices[i]);
            return res = max(dfs(i - 1, j, false), dfs(i - 1, j, true) + prices[i]);
        };
        return dfs(n - 1, k, false);
    }
};
// @lc code=end

