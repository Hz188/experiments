/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        for(int j = 0; j <= m; ++j){
            f[0][j] = j;
        }
        for(int i = 0; i < n; ++i) {
            f[i+1][0] = i+1;
            for(int j = 0; j < m; ++j) {
                f[i+1][j+1] = s[i] == t[j] ? f[i][j]: 
                    min(f[i][j+1], min(f[i+1][j], f[i][j])) + 1;
            }
        }
        return f[n][m];
    }
};
// @lc code=end

