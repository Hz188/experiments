/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int left = 0;
        int right = 0;
        int prod = 1;
        int ans = 0;
        while(right < n) {
            prod *= nums[right];
            right++;

            while (prod >= k){
                prod /= nums[left];
                left++;
            }
            //[l, r) 有多少个: r-l
            ans += right - left;
        }
        return ans;
    }
};
// @lc code=end

