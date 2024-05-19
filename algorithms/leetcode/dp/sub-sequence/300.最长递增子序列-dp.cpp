/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> memo(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; ++j) {
                if(nums[j] < nums[i])
                    memo[i] = max(memo[j] + 1, memo[i]);
            }
        }
        return *max_element(memo.begin(), memo.end());
    }
};
// @lc code=end

