/*
 * @lc app=leetcode.cn id=1314 lang=cpp
 *
 * [1314] 矩阵区域和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        auto pre_sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pre_sum[i+1][j+1] = pre_sum[i+1][j] + pre_sum[i][j+1] - pre_sum[i][j] + mat[i][j];
            }
        }
        vector<vector<int>> res(m, vector<int>(n, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int x1 = i - k < 0 ? 0 : i - k;
                int y1 = j - k < 0 ? 0 : j - k;
                int x2 = i + k >= m ? m-1 : i + k;
                int y2 = j + k >= n ? n-1 : j + k;
                res[i][j] = 
                        pre_sum[x2+1][y2+1] 
                        - pre_sum[x2+1][y1] - pre_sum[x1][y2+1] + pre_sum[x1][y1];
            }
        }
        return res;
    }
};
// @lc code=end

