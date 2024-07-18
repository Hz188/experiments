/*
 * @lc app=leetcode.cn id=724 lang=cpp
 *
 * [724] 寻找数组的中心下标
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        auto pre_sum = vector(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++){
            pre_sum[i+1] = nums[i] + pre_sum[i];  // pre_sum [i+1] = [0..i+1)
        }
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            int l_sum = pre_sum[i];
            int r_sum = pre_sum[n] - pre_sum[i+1];
            if(l_sum == r_sum) return i;
        }
        return -1;
    }
};
// @lc code=end

