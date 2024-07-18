/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 0; // [0...k] 无重复数组
        int n = nums.size();
        for(int i = 1; i < n; i++) {
            if(nums[i] == nums[k]) continue;
            nums[++k] = nums[i];
        }
        return k+1;
    }
};
// @lc code=end

