/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // 1. memo
        // vector<vector<int>> memo(n, vector<int>(2, -1));
        // function<int(int, bool)> dfs = [&] (int i, bool hold) -> int {

        //     if(i < 0)
        //         return hold? INT_MIN: 0;
        //     int &res = memo[i][hold];
        //     if (res != -1) return res;
        //     if(hold)
        //         return res = max(dfs(i-1,  1), dfs(i-2, 0) - prices[i]);
        //     return res = max(dfs(i-1, 0), dfs(i-1, 1) + prices[i]);
        // };
        // return dfs(n-1, 0);

        // 2. dp
        vector<vector<int>> f(n+1, vector<int>(2, -1));
        f[0][0] = 0;
        f[0][1] = INT_MIN;
        for(int i = 0; i < n; i++) {
            f[i+1][0] = max(f[i][0], f[i][1] + prices[i]);
            if(i == 0)
                f[i+1][1] = max(f[i][1], - prices[i]);
            else
                f[i+1][1] = max(f[i][1], f[i-1][0] - prices[i]);
        }
        return f[n][0];
    }
};
// @lc code=end

