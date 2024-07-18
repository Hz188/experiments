/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int min_diff = INT_MAX;
        for(int i = 0; i < n-2; i++) {
            int x = nums[i];
            if (i > 0 && x == nums[i - 1]) {
                continue; // 优化三
            }

            // 优化一
            int s = x + nums[i + 1] + nums[i + 2];
            if (s > target) { // 后面无论怎么选，选出的三个数的和不会比 s 还小
                if (s - target < min_diff) {
                    ans = s; // 由于下面直接 break，这里无需更新 min_diff
                }
                break;
            }

            // 优化二
            s = x + nums[n - 2] + nums[n - 1];
            if (s < target) { // x 加上后面任意两个数都不超过 s，所以下面的双指针就不需要跑了
                if (target - s < min_diff) {
                    min_diff = target - s;
                    ans = s;
                }
                continue;
            }

            int l = i+1;
            int r = n-1;
            while(l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if(sum == target) return target;
                if(sum > target) {
                    int cur_diff = sum - target;
                    if (cur_diff < min_diff) {
                        ans = sum;
                        min_diff = cur_diff;
                    }
                    r--;
                } else {  // sum < target
                    int cur_diff = target - sum;
                    if (cur_diff < min_diff) {
                        ans = sum;
                        min_diff = cur_diff;
                    }
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

