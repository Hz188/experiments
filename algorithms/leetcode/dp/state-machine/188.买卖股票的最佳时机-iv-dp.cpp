/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size(), f[n + 1][k + 2][2];
        memset(f, -0x3f, sizeof(f));
        for (int j = 1; j <= k + 1; j++) {
            f[0][j][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= k + 1; ++j) {
                f[i + 1][j][0] = max(f[i][j][0], f[i][j][1] + prices[i]);
                f[i + 1][j][1] = max(f[i][j][1], f[i][j - 1][0] - prices[i]);
            }
        }
        return f[n][k + 1][0];
    }
};
// @lc code=end

