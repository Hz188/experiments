/*
 * @lc app=leetcode.cn id=2779 lang=cpp
 *
 * [2779] 数组的最大美丽值
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 0;
        for(int left = 0, right = 0; right < n; right++) {
            if(nums[right] - nums[left] > 2*k) {
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

