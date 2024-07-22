/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> window{};
        int ans {0};
        int left = 0;
        for(int right = 0; right < n; right++) {
            int c = nums[right];
            window[c]++;
            while(window[c] > k) {
                int d = nums[left];
                window[d]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

