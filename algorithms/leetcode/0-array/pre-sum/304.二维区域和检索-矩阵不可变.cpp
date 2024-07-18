/*
 * @lc app=leetcode.cn id=304 lang=cpp
 *
 * [304] 二维区域和检索 - 矩阵不可变
 */

// @lc code=start
#include <vector>
using namespace std;
class NumMatrix {
    vector<vector<int>> pre_sum{};
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        pre_sum = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                pre_sum[i+1][j+1] = pre_sum[i+1][j] + pre_sum[i][j+1] - pre_sum[i][j] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return pre_sum[row2+1][col2+1] - pre_sum[row2+1][col1] - pre_sum[row1][col2+1] + pre_sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
// @lc code=end

