/*
 * @lc app=leetcode.cn id=1771 lang=cpp
 *
 * [1771] 由子序列构造的最长回文串的长度
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        auto s = word1 + word2;
        int n = s.length();
        int ans;

        // 1. memo
        vector<vector<int>> memo(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if(i >= j) return 1;
            if(i > j) return 0;

            int& res = memo[i][j];
            if(res != -1) return res;
            if(s[i] == s[j]) {
                res = dfs(i+1, j-1) + 2;
                if(i < word1.length() & j >= word1.length())
                    ans = max(ans, res);
                return res;
            } else {
                return res = max(dfs(i+1, j), dfs(i, j-1));
            }

        };

        dfs(0, n-1);
        return ans;
        // 2. dp
        // int f[n][n];
        // memset(f, 0, sizeof(f));
        // for (int i = n - 1; i >= 0; --i) {
        //     f[i][i] = 1;
        //     for (int j = i + 1; j < n; ++j) {
        //         if (s[i] == s[j]) {
        //             f[i][j] = f[i + 1][j - 1] + 2;
        //             if (i < word1.length() && j >= word1.length()) {
        //                 ans = max(ans, f[i][j]); // f[i][j] 一定包含 s[i] 和 s[j]
        //             }
        //         } else {
        //             f[i][j] = max(f[i + 1][j], f[i][j - 1]);
        //         }
        //     }
        // }
        // return ans;
    }
};
// @lc code=end

