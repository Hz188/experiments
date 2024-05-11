/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r =  n - 1;
        int res = -1;
        while (l < r) {
            int cur_res = min(height[l], height[r]) * (r - l);
            res = max(res, cur_res);
            if(height[l] > height[r]) {
                r--;
            } else {
                l++;
            }
        }
        return res;
    }
};
// @lc code=end

