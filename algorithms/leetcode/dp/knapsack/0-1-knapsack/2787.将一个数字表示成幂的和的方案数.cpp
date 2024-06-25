/*
 * @lc app=leetcode.cn id=2787 lang=cpp
 *
 * [2787] 将一个数字表示成幂的和的方案数
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int numberOfWays(int n, int x) {
        int MOD = 1e9 + 7;
        //[1 ... n-1] -> [1 ... n-1^x] -> 填充背包 n 的方案数
        int end = 0;
        if (x >= 2)
            end = (int)sqrt(n);
        else 
            end = n;
        vector<vector<int>> memo(end+1, vector<int>(n+1, -1));
        function<int(int, int)> dfs = [&] (int i, int c)  {
            if(i == 0) 
                return c == 0 ? 1 : 0;
            // cout << i << ", " << c << endl; 
            int& res = memo[i][c];
            if(res != -1) return res;
            int cur = pow(i, x);
            if(cur > c) return res = dfs(i-1, c) % MOD;
            return res = (dfs(i-1, c) % MOD + dfs(i-1, c - cur) % MOD) % MOD;
        };

        return dfs(end, n);
    }

    int pow(int a, int b) {
        int res = 1;
        for(int i = 0; i < b; i++) {
            res *= a;
        }
        return res;
    }
};
// @lc code=end

