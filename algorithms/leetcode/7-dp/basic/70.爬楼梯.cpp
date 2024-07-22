/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
#include <functional>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {

        // 记忆化搜索
        vector<int> memo(n+1, -1);
        function<int(int)> dfs = [&](int i) {
            if(i == 0) return 1;
            if(i == 1) return 1;
            int& res = memo[i];
            if (res != -1) return res;
            return res = dfs(i-1) + dfs(i-2);
        };

        return dfs(n);
        // 递归 -> 递归
        // dp
        vector<int> f(n+1, 0);
        f[0] = f[1] = 1;
        for(int i = 0; i <= n-2; ++i) {
            f[i+2] = f[i+1] + f[i];
        }
        return f[n];

        // 压缩
        int f0 = 1, f1 = 1;
        for(int i = 0; i <= n-2; ++i) {
            int f2 = f0 + f1;
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
};
// @lc code=end

