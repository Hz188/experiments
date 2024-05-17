/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        // step 1. 思考回溯怎么写
            /*
            function<int(int)> dfs = [&](int i)  -> int {
                if(i < 0) {
                    return 0;
                }
                int res = max(dfs(i-1), dfs(i-2) + nums[i]);
                return res;
            };
            return dfs(n-1);// 提交会超时
            */
        // step 2. 画出回溯树，寻找重叠子问题，加 memo，改记忆化搜索
            /*
            vector<int> memo(n, -1);
            function<int(int)> dfs = [&](int i)  -> int {
                if(i < 0) {
                    return 0;
                }
                if(memo[i] != -1) return memo[i];
                int res = max(dfs(i-1), dfs(i-2) + nums[i]);
                return memo[i] = res;
            };
            return dfs(n-1);
            */
        // step 3. 改递推表达形式
        vector<int> memo(n+1); // dfs(n-1)表示抢到n-1的最大值
        //那么memo[n] 表示抢到[0...n-1]的最大值
        //注意索引的偏移
        memo[0] = 0;
        memo[1] = nums[0];
        for(int i = 2; i <= n; i++) {
            memo[i] = max(memo[i-1], memo[i-2] + nums[i-1]);
        }
        return memo[n];
    }
};
// @lc code=end

