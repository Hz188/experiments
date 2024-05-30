/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = -1, right = nums.size() - 1; // 开区间 (-1, n-1)
        while (left + 1 < right) { // 开区间不为空
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[right]) right = mid; // 蓝色
            else if (nums[mid] > nums[right]) left = mid; // 红色
            else --right;
        }
        return nums[right];
    }
};
// @lc code=end

