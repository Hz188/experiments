/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 *
 * [2915] 和为目标值的最长子序列的长度
 */

// @lc code=start
#include <functional>
#include <vector>
using namespace std;
class Solution {
public:
    //依旧是填满背包target的最大价值（相当于每个nums[i]的价值是1
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n = nums.size();
        // 1. 记忆化搜索
        // vector<vector<int>> memo(n, vector<int>(target+1, INT_MIN));
        // function<int(int, int)> dfs = [&] (int i, int c) {
        //     if (i < 0)
        //         return c == 0 ? 0 : INT_MIN;
        //     int& res = memo[i][c];
        //     if(res != INT_MIN) return res;
        //     if(c < nums[i]) return res = dfs(i-1, c);
        //     return res = max(dfs(i-1, c),  dfs(i-1, c - nums[i])+1);
        // };
        // int res = dfs(n-1, target);
        // return res < 0 ? -1: res;

        // 2. 递推
        // i == -1 -> i+1 偏移处理 所以 f(n) -> f(n+1)
        vector<vector<int>> f(n+1, vector<int>(target + 1, INT_MIN));
        f[0][0] = 0;
        for(int i = 0; i < n; i++) {
            for(int c = 0; c <= target; c++) {
                if(c < nums[i])
                    f[i+1][c] = f[i][c];
                else
                    f[i+1][c] = max(f[i][c], f[i][c-nums[i]]+1);
            }
        }
        return f[n][target] < 0 ? -1: f[n][target];


        // 3. 空间优化 两个数组
        // 4. 空间优化 一个数组
    }
};
// @lc code=end

