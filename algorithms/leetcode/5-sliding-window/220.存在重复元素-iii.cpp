/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 */

// @lc code=start
#include <vector>
#include <set>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int k, int t) {
        std::set<long> window;
        int left = 0, right = 0;
        while (right < nums.size()) {
            // 为了防止 i == j，所以在扩大窗口之前先判断是否有符合题意的索引对 (i, j)
            // 查找略大于 nums[right] 的那个元素
            auto ceiling = window.lower_bound((long)nums[right]);
            if (ceiling != window.end() && *ceiling - nums[right] <= t) {
                return true;
            }
            // 查找略小于 nums[right] 的那个元素
            auto floor = ceiling;
            if (floor != window.begin()) {
                --floor;
                if (nums[right] - *floor <= t) {
                    return true;
                }
            }

            // 扩大窗口
            window.insert(nums[right]);
            right++;

            if (right - left > k) {
                // 缩小窗口
                window.erase(nums[left]);
                left++;
            }
        }
        return false;
    }
};
// @lc code=end

