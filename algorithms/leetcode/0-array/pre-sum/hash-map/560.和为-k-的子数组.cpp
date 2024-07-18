/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre_sum(n + 1);
        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }

        int ans = 0;
        unordered_map<int, int> count;
        count[0] = 1;
        int res = 0;

        for (int i = 1; i <= n; i++) {
            int need = pre_sum[i] - k;
            if (count.contains(need)) {
                res += count[need];
            }
            count[pre_sum[i]]++;
        }
        return res;
    }
};
// @lc code=end

