/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        auto max_it = max_element(nums.begin(), nums.end());

        int n = nums.size();

        vector<int> f1(n, 1), f2(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]) {
                    f1[i] = max(f1[j] + 1, f1[i]);
                }
            }
        }

        for(int i = n-1; i >= 0; i--) {
            for(int j = n-1; j > i; j--) {
                if(nums[i] > nums[j]) {
                    f2[i] = max(f2[j] + 1, f2[i]);
                }
            }
        }
        int ans = n;
        for(int i = 1; i < n-1; i++) { // 先排除首尾，至少3个元素
            if(f1[i] == 1 || f2[i] == 1) continue; // 再排除 == 1的情况，如果 ==1，说明是单侧山峰，而不是双侧山峰
            ans = min(ans, n - f1[i] - f2[i] + 1);
        }
        return ans;
    }
};
// @lc code=end

