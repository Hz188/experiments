/*
 * @lc app=leetcode.cn id=1277 lang=cpp
 *
 * [1277] 统计全为 1 的正方形子矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(matrix[i][j] == 1) {
                    if (i == 0 || j == 0) {//第一行和第一列的，只能各自构成一个正方形
                        dp[i][j] = 1;
                        ans++;
                        continue;
                    }
                    dp[i][j] = min(min(dp[i][j-1], dp[i-1][j]), dp[i-1][j-1]) + 1;
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
// @lc code=end

