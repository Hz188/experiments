/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-2; // n-1 在最右侧，一定是蓝色
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] >= nums[n-1]) {  // 题意说了，元素互不相等，所以这个=号不会触发
                // mid 红色
                left = mid + 1; 
            } else {
                // 蓝色
                right = mid - 1;
            }
        }
        return nums[left];
    }
};
// @lc code=end

