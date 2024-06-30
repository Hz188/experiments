/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(2, vector<int>(m+1, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                dp[(i+1) % 2][j+1] = s[i] == t[j]
                                    ? dp[i%2][j] +1 
                                    : max(dp[i % 2][j+1], dp[(i+1)%2][j]);
            }
        }
        return dp[n%2][m];
    }
};
// @lc code=end

