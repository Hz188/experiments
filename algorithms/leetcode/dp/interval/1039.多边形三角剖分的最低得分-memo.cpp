/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, INT_MAX));
        function<int(int,int)> dfs = [&](int i, int j) -> int {
            if(i+1 == j) return 0;
            int& res = memo[i][j];
            if(res != INT_MAX) return res;
            for(int k = i+1; k < j; ++k) {
                res = min(res, dfs(i, k) + dfs(k, j) + values[i] * values[j] * values[k]);
            }
            return res;
        };
        return dfs(0, n-1);
    }
};
// @lc code=end

