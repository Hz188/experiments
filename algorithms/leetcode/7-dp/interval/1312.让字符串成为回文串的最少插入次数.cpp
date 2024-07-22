/*
 * @lc app=leetcode.cn id=1312 lang=cpp
 *
 * [1312] 让字符串成为回文串的最少插入次数
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        // 1. memo
        auto memo = vector<vector<int>>(n, vector<int>(n, -1));
        function<int(int, int)> dfs = [&] (int i, int j) {
            if(i >= j) return 0;
            int& res = memo[i][j];
            if(res != -1) return res;
            res = INT_MAX;
            if(s[i] == s[j]) 
                res = dfs(i+1, j-1);
            else {
                res = min(dfs(i+1, j), dfs(i, j-1)) + 1;
            }
            return res;
        };
        // return dfs(0, n-1);

        // 2. dp
        auto f = vector<vector<int>>(n, vector<int>(n, 0));
        for(int i = n-2; i >= 0; i--) {
            for(int j = i+1; j < n; j++){
                if(s[i] == s[j])
                    f[i][j] = f[i+1][j-1];
                else 
                    f[i][j] = min(f[i+1][j], f[i][j-1]) + 1;
            }
        }
        return f[0][n-1];
        
    }
};
// @lc code=end

