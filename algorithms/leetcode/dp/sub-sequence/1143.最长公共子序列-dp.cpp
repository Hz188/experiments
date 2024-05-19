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
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                f[i+1][j+1] = s[i] == t[j] ? f[i][j] + 1: max(f[i][j+1], f[i+1][j]);
            }
        }
        return f[n][m];
    }
};
// @lc code=end

