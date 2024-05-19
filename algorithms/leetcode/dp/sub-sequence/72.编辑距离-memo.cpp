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
        vector<vector<int>> memo(n, vector<int>(m, -1));
        function<int(int, int)> dfs = [&](int i, int j) {
            if(i < 0) return j+1;
            if(j < 0) return i+1;
            int& res = memo[i][j];
            if(res != -1) return memo[i][j];
            if(s[i] == t[j])
                return res = dfs(i-1, j-1);
            return res = min(dfs(i-1, j), min(dfs(i, j-1), dfs(i-1, j-1))) + 1;
        };
        return dfs(n-1, m-1);
    }
};
// @lc code=end

