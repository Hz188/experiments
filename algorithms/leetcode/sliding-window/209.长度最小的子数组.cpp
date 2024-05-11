// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem209.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n  = nums.size();
        int ans = n+1;
        int s = 0;
        int left = 0; // 左端点
        // for(int right = 0; right < n; right++) { // 枚举右端点
        int right = 0;
        while(right < n) {
            int x = nums[right];
            right++; //窗口扩大
            s += x;
            // 写法1
            /*
            while(s - nums[left] >= target) {
                s -= nums[left];
                left++;
            }
            if (s >= target) {
                ans = min(ans, right - left + 1);
            }
            */
            // 写法 2
            while(s >= target) {
                ans = min(ans, right - left);
                s -= nums[left];
                left++; // 窗口减小
            }
        }
        return ans <= n ? ans : 0;
    }
};
// @lc code=end

