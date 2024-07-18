/*
 * @lc app=leetcode.cn id=303 lang=cpp
 *
 * [303] 区域和检索 - 数组不可变
 */

// @lc code=start
#include <vector>
using namespace std;
class NumArray {
    vector<int> pre_sum{};
public:
    NumArray(vector<int>& nums) {
        pre_sum = vector(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            pre_sum[i+1] = nums[i] + pre_sum[i];  // pre_sum [i+1] = [0..i+1)
        }
    }
    
    int sumRange(int left, int right) {
        return pre_sum[right+1] - pre_sum[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
// @lc code=end

