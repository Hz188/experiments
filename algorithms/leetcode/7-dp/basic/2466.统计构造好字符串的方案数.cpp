/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */

// @lc code=start
#include <functional>
#include <string>
using namespace std;
class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        const int MOD = 1'000'000'007;
        int ans = 0;
        vector<int> f(high + 1); // f[i] 表示构造长为 i 的字符串的方案数
        f[0] = 1; // 构造空串的方案数为 1
        for (int i = 1; i <= high; i++) {
            // 爬楼梯变形
            if (i >= zero) f[i] = (f[i] + f[i - zero]) % MOD;
            if (i >= one)  f[i] = (f[i] + f[i - one]) % MOD;
            if (i >= low)  ans = (ans + f[i]) % MOD;
        }
        return ans;
    }
};
// @lc code=end

