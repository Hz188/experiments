/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */

// @lc code=start
#include <functional>
#include <vector>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];



        // 1. 回溯 -> 2. 记忆化搜索
        vector<int> memo1(n, -1);
        vector<int> memo2(n, -1);
        return max(dfs(0, n-2, memo1, nums), dfs(1, n-1, memo2, nums));

        // 3. 递推 相当于两个198题，选最大
        return max(nums[0] + rob1(nums, 2, n - 1), rob1(nums, 1, n));

    }

    // 198. 打家劫舍
    int rob1(vector<int> &nums, int start, int end) { // [start,end) 左闭右开
        int f0 = 0, f1 = 0;
        for (int i = start; i < end; i++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }

    int dfs(int i, int end, vector<int>& memo, vector<int>& nums) {
            if(i > end) return 0;
            int& res = memo[i];
            if(res != -1) return res;
            return res = max(dfs(i+2, end, memo, nums) + nums[i], dfs(i+1, end, memo, nums));
    }
};
// @lc code=end

