/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        auto pre_sum = vector<int>(n+1, 0);
        auto val_to_idx = unordered_map<int, int>{};
        for(int i = 0; i < n; i++) {
            pre_sum[i+1] = pre_sum[i] + (nums[i] == 0? -1: 1);
            // val_to_idx[pre_sum[i+1]] = i+1;
        }
        int res = 0;
        for(int i = 0; i < pre_sum.size(); i++) {
            // pre_sum[i+1] 是当前和，为了凑0，需要找之前也这么大的和，作差得到区间和为0
            if(val_to_idx.count(pre_sum[i])) //找到了
                res = max(res, i - val_to_idx[pre_sum[i]]);
            else  //没找到，放进去
                val_to_idx[pre_sum[i]] = i;
        }
        return res;

        

    }
};
// @lc code=end

