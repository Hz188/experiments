/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();  // 1
        int n = matrix[0].size(); // 2
        int top = 0, left = 0;
        int bottom = m-1, right = n-1;

        while(top <= bottom && left <= right) {
            int cur = matrix[bottom][left];
            if(target > cur) {
                left++;
            } else if (target < cur) {
                bottom--;
            } else {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

