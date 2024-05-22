/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        auto f = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            f[i][i] = 1;
        }
        for(int i = n-1; i >= 0; i--){ 
            for(int j = i+1; j < n; j++){ 
                if(s[i] == s[j]) {
                    f[i][j] = f[i+1][j-1] + 2;
                } else {
                    f[i][j] = max(f[i+1][j], f[i][j-1]);
                }
            }
        }
        return f[0][n-1];
    }
};
// @lc code=end

