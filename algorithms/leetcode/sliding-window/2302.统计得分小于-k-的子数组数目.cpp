/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */

// @lc code=start
#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = nums.size();
        long long ans = 0;
        int left = 0;
        int pre_left = 0;
        vector<long long> pre_sum(n+1, 0); // pre_sum[i] == [0...i)
        for(int i = 0; i < n; i++) {
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        long long score = 0;
        for(int right = 0; right < n; ++right) {
            score = (pre_sum[right+1] - pre_sum[left]) * (right - left + 1);
            while(score >= k) {
                left++;
                score = (pre_sum[right+1] - pre_sum[left]) * (right - left + 1);
            }
            ans += right - left + 1;
        }
        return ans;
    }

};
// @lc code=end

