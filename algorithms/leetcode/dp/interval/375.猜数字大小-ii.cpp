/*
 * @lc app=leetcode.cn id=375 lang=cpp
 *
 * [375] 猜数字大小 II
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int getMoneyAmount(int n) {
        // 1. memo
        auto memo = vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX));
        // dfs(i, j) -> 猜测区间[i,j]确保获胜的最小现金数
        function<int(int, int)> dfs = [&](int i, int j) {
            if(i == j) return 0; // i == j 一定能猜中 不花钱
            if(i+1 == j) return i; // i+1 == j 猜i之后，下次一定能猜中 花费 i
            if(i+2 == j) return i+1; // i+2 == j 猜中间值i+1 下次一定能猜中 花费 i+1
            int& res = memo[i][j];
            if(res != INT_MAX) return res;
            for(int k = i+1; k < j; k++) {
                int ans = k + max(dfs(i, k-1), dfs(k+1, j)); // 猜测 k，猜错会有两个转移：[i, k-1] or [k+1, j]，花费是k
                res = min(res, ans);
            }
            return res;
        };
        // return dfs(1, n);
        
        // 2. dp
        auto f = vector<vector<int>>(n+1, vector<int>(n+1, INT_MAX));
        for(int i = n; i > 0; i--) {
            for(int j = i; j <= n; j++) {
                if(i == j) {
                    f[i][j] = 0;
                    continue;
                }
                if(i+1 == j) {
                    f[i][j] = i;
                    continue;
                }
                for(int k = i+1; k < j; k++) {
                    int ans = k + max(f[i][k-1], f[k+1][j]);
                    f[i][j] = min(f[i][j], ans);
                }
            }
        }
        return f[1][n];

    }
};
// @lc code=end

