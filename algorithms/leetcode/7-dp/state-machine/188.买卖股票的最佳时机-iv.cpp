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
    int maxProfit(int k, vector<int> &prices) {
        // 1. memo
        // int n = prices.size();
        // vector<vector<vector<int>>> memo(n, vector<vector<int>>(k+1, {-1,-1}));// -1 表示还没有计算过
        // function<int(int, int, bool)> dfs = [&](int i, int j, bool hold) -> int {
        //     if (j < 0) return INT_MIN / 2; // 防止溢出
        //     if (i < 0) return hold ? INT_MIN / 2 : 0;
        //     int &res = memo[i][j][hold]; // 注意这里是引用
        //     if (res != -1) return res; // 之前计算过
        //     if (hold) return res = max(dfs(i - 1, j, true), dfs(i - 1, j - 1, false) - prices[i]);
        //     return res = max(dfs(i - 1, j, false), dfs(i - 1, j, true) + prices[i]);
        // };
        // return dfs(n - 1, k, false);

        // 2. dp
        // int n = prices.size(), f[n + 1][k + 2][2];
        // memset(f, -0x3f, sizeof(f));
        // for (int j = 1; j <= k + 1; j++) {
        //     f[0][j][0] = 0;
        // }
        // for (int i = 0; i < n; i++) {
        //     for (int j = 1; j <= k + 1; ++j) {
        //         f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + prices[i]);
        //         f[i + 1][j][1] = max(f[i][j][1], f[i][j - 1][0] - prices[i]);
        //     }
        // }
        // return f[n][k + 1][0];

        // 3. dp compression
        int n = prices.size();
        vector<vector<int>> f(k+2, vector<int>(2, INT_MIN / 2));
        for(int j = 1; j <= k+1; j++) {
            f[j][0] = 0;
        }
        for(int i = 0; i < n; i++) {
            for(int j = k+1; j >= 1; j--) {  //这里倒序遍历，分析一下就可以发现和0-1背包一样，我们需要保证前面状态已经计算、切不覆盖
                f[j][0] = max(f[j][0], f[j][1] + prices[i]);
                f[j][1] = max(f[j][1], f[j-1][0] - prices[i]);
            }
        }
        return f[k+1][0];

    }
};
// @lc code=end

