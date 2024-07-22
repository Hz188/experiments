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
        vector<vector<int>> memo(n, vector<int>(m, -1));
        function<int(int, int)> dfs = [&](int i, int j) {
            if(i < 0 || j < 0) // < 0 表示其中一个字符串为空
                return 0;
            int& res = memo[i][j];
            if(res != -1) return memo[i][j];
            if(s[i] == t[j])
                return res = dfs(i-1, j-1) + 1;
            return res = max(dfs(i-1, j), dfs(i, j-1));
        };
        return dfs(n-1, m-1);
    }
};
// @lc code=end

