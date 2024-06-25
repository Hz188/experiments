/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();

        // 1. 回溯
        /*
        function<int(int)> dfs = [&](int i) {
            if(i == 0) return 1;
            int res = 0;
            for(auto step: nums){
                if(step <= i)
                    res += dfs(i-step);
            }
            return res;
        };
        return dfs(target);
        */

        // 2. 记忆化搜索
        /*
        vector<int> memo(target+1, -1);
        function<int(int)> dfs = [&](int i) {
            if(i == 0) return 1;
            int& res = memo[i];
            if(res != -1) return res;
            res = 0;
            for(auto step: nums) {
                if(step <= i)
                    res += dfs(i-step);
            }
            return res;
        };
        return dfs(target);
        */
        // 3. 递归 -> 递推
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int x : nums) {
                if (x <= i) {
                    f[i] += f[i - x];
                }
            }
        }
        return f[target];
    }
};
// @lc code=end

