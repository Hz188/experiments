/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0, right = n-2; // n-1 在最右侧，一定是蓝色
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            if(is_blue(nums, mid, target)) { 
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        if(nums[left] != target) return -1;
        return left;
    }
private:
    bool is_blue(vector<int>& nums, int i, int target) {
        int end = nums.back();
        if(nums[i] > end) {
            return target > end && nums[i] >= target;
        } else {
            return target > end || nums[i] >= target; 
        }
        /*一共是三种情况为蓝色：
            1. nums[i] 和 target在同一段
                1.1 nums[i] > end, target > end: 两个都在左段，那么nums[i] >= target 在target右侧，为蓝色
                1.2 nums[i] < end, nums[i]在右段，但nums[i] >= target（这里隐含了target也在右段） 在target右侧，为蓝色
            2. nums[i] 和 target不在同一段
                nums[i] < end, target > end: nums[i]在右段，target在左段，nums[i]一定在target右侧，为蓝色
        */
    }
};
// @lc code=end

