/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int numSquares(int n) {
        int end = (int)sqrt(n);
        vector<vector<int>> memo(end+1, vector(n+1, -1));
        function<int(int, int)> dfs = [&] (int i, int c) {
            if(i == 0)
                return c == 0 ? 0 : 100000;
            int& res = memo[i][c];
            if(res != -1) 
                return res;
            if(i * i > c)
                return res = dfs(i-1, c);
            return res = min(dfs(i-1, c),  dfs(i, c-i*i) +1);
        };
        return dfs(end, n);
    }
};
// @lc code=end

