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
        // 1. memo
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
        // return dfs(0, n-1);

        // 2. dp
        vector<vector<int>> f(n, vector<int>(n, 0));

        for(int i = n-3; i >= 0; --i){ // i,k,j要有意义所以起码n-3 n-2 n-1
            for(int j = i+2; j < n; ++j) {
                int res = INT_MAX;
                for(int k = i+1; k < j; ++k) {
                    res = min(res, f[i][k]+f[k][j]+values[i]*values[j]*values[k]);
                }
                f[i][j] = res;
            }
        }
        return f[0][n-1];
    }
};
// @lc code=end

