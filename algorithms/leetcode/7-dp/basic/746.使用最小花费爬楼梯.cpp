/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @lc code=start
#include <functional>
#include <vector>
using namespace std;
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();  // 台阶顶部

        // 1. 回溯切入
        /*
        function<int(int)> dfs = [&] (int i) {
            if(i == 0) return 0; 
            if(i == 1) return 0;

            int res = 0;
            res = min(dfs(i-1) + cost[i-1], dfs(i-2) + cost[i-2]);
            return res;
        };
        return dfs(n);
        */

        // 2. 记忆化搜索
        /*
        vector<int> memo(n+1, -1);
        function<int(int)> dfs = [&] (int i) {
            if(i == 0) return 0;
            if(i == 1) return 0;
            int& res = memo[i];
            if(res != -1) return res;
            return res = min(dfs(i-1) + cost[i-1], dfs(i-2) + cost[i-2]);
        };
        return dfs(n);
        */


        // 3. 1:1 翻译递推
        vector<int> f(n+1, -1);
        f[0] = f[1] = 0;
        for(int i = 2; i <= n; i++) {
            f[i] = min(f[i-1] + cost[i-1], f[i-2] + cost[i-2]);
        }
        return f[n];
        
        // 4. compression

        // int f0 = 0, f1 = 0;
        // for(int i = 2; i <= n; i++) {
            // int f2 = min(f1 + cost[i-1], f0 + cost[i-2]);
            // f0 = f1;
            // f1 = f2;
        // }
        // return f1;
    }
};
// @lc code=end

