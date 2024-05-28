/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        auto check = [&](int limit) -> bool {
            long long extra = 0;
            for(int i = nums.size() - 1; i > 0; i--) {
                extra = max(nums[i] + extra - limit, 0LL);
            }
            return nums[0] + extra <= limit;
        };
        //开区间
        int left = -1, right = *max_element(nums.begin(), nums.end());
        while(left + 1 < right) {
            int mid = (right - left) / 2 + left;
            (check(mid) ? right : left) = mid;
        }
        return right;
    }


};
// @lc code=end

