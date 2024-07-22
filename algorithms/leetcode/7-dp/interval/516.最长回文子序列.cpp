/*
 * @lc app=leetcode.cn id=516 lang=cpp
 *
 * [516] 最长回文子序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
class Solution {
    vector<vector<int>> memo{};
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        // 1. memo
        memo = vector<vector<int>>(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if(i == j) return 1;
            if(i > j) return 0;
            int& res = memo[i][j];
            if (res != -1) return res;
            if(s[i] == s[j])
                return res = dfs(i+1, j-1)+2;
            return res = max(dfs(i+1, j), dfs(i, j-1));
        };
        // return dfs(0, n-1);

        // 2. dp
        auto f = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = 0; i < n; i++) {
            f[i][i] = 1;
        }
        for(int i = n-1; i >= 0; i--){  // i+1 -> i 所以i要倒序遍历
            for(int j = i+1; j < n; j++){  // j-1/j -> j 所以j要正序遍历
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

