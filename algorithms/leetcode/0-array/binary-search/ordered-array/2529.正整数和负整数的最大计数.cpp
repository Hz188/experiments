/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int pos = left_bound(nums, 1);
        int neg = left_bound(nums, 0) - 1;
        return max(n-pos, neg+1);
    }
private:
    int left_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int l = -1, r = n;
        while(l + 1 < r) { 
            int mid = (r - l) / 2 + l;
            if(nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
};
// @lc code=end

