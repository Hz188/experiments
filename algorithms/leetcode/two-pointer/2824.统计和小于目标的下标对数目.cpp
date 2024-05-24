/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
        int n = nums.size();
        int ans {0};
        sort(nums.begin(), nums.end());
        int l = 0, r = n-1;
        while(l < r) {
            int sum = nums[l] + nums[r];
            if(sum  >= target) {
                r--;
            } else {
                ans += r-l;
                l++;
            }
        }
        return ans;
    }
};
// @lc code=end

