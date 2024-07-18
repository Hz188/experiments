/*
 * @lc app=leetcode.cn id=523 lang=cpp
 *
 * [523] 连续的子数组和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        auto pre_sum = vector<int>(n+1, 0);
        auto val_to_idx = unordered_map<int, int>{};
        for(int i = 0; i < n; i++) {
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        for(int i = 0; i < pre_sum.size(); i++) {   
            if(!val_to_idx.count(pre_sum[i] % k))
                val_to_idx[pre_sum[i] % k] = i;
        }
        for(int i = 1; i < pre_sum.size(); i++) {
            int need = pre_sum[i] % k;
            if (val_to_idx.count(need)) {
                if(i - val_to_idx[need] >=2)
                    return true;
            }
        }
        return false;
    }
};
// @lc code=end

