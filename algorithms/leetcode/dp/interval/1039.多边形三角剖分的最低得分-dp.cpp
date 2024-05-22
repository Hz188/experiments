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
        vector<vector<int>> memo(n, vector<int>(n, 0));

        for(int i = n-3; i >= 0; --i){ // i,k,j要有意义所以起码n-3 n-2 n-1
            for(int j = i+2; j < n; ++j) {
                int res = INT_MAX;
                for(int k = i+1; k < j; ++k) {
                    res = min(res, memo[i][k]+memo[k][j]+values[i]*values[j]*values[k]);
                }
                memo[i][j] = res;
            }
        }
        return memo[0][n-1];
    }
};
// @lc code=end

