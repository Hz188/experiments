/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target < 0) return -1;
        int left = 0;
        int ans = -1;
        int cur = 0;
        for(int right = 0; right < n; right++) {
            cur += nums[right];
            while(cur > target) {
                cur -= nums[left];
                left++;
            }
            if(cur == target)
                ans = max(ans, right-left+1);
        }
        return ans < 0? -1: n - ans;
    }
};
// @lc code=end

