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
    vector<vector<int>> memo{};
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        memo = vector<vector<int>>(n, vector<int>(n, -1));

        return dfs(s, 0, n-1);
    }
    int dfs(string& s, int i, int j) {
        if(i == j) return 1;
        if(i > j) return 0;
        int& res = memo[i][j];
        if (res != -1) return res;
        if(s[i] == s[j])
            return res = dfs(s, i+1, j-1)+2;
        else
            return res = max(dfs(s, i+1, j), dfs(s, i, j-1));
    }
};
// @lc code=end

