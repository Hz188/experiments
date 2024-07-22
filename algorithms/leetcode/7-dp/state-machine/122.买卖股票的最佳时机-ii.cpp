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

        // 1. memo
        // vector<vector<int>> memo(n, vector<int>(2, -1));
        // function<int(int, bool)> dfs = [&] (int i, bool hold) -> int {

        //     if(i < 0)
        //         return hold? INT_MIN: 0;
        //     int &res = memo[i][hold];
        //     if (res != -1) return res;
        //     if(hold)
        //         return res = max(dfs(i-1,  1), dfs(i-1, 0) - prices[i]);
        //     return res = max(dfs(i-1, 0), dfs(i-1, 1) + prices[i]);
        // };
        // return dfs(n-1, 0);

        // 2. dp
        vector<vector<int>> f(n+1, vector<int>(2, -1));
        f[0][0] = 0;
        f[0][1] = INT_MIN;
        for(int i = 0; i < n; i++) {
            f[i+1][0] = max(f[i][0], f[i][1] + prices[i]);
            f[i+1][1] = max(f[i][1], f[i][0] - prices[i]);
        }
        return f[n][0];

        // 3. dp compression 
        //优化：今天结果之和前一天的两个状态有关，再之前的就无关了
        // int f0 = 0, f1 = INT_MIN;
        // for(int i = 0; i < n; i++) {
        //     int temp_f0 = max(f0, f1 + prices[i]);
        //     f1 = max(f1, f0 - prices[i]);
        //     f0 = temp_f0;
        // }
        // return f0;
    }
};
// @lc code=end

