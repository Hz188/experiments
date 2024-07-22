/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> window;
        // 滑动窗口算法框架，维护一个大小为 k 的窗口
        for(int left = 0, right = 0; right < nums.size(); right++) {
            // 扩大窗口
            window[nums[right]]++;
            if (right - left + 1 > k+1) {
                // 当窗口的大小大于 k+1 时，缩小窗口
                window[nums[left]]--;
                left++;
            }
            if(window[nums[right]] >= 2) return true;

        }
        return false;

    }
};
// @lc code=end

