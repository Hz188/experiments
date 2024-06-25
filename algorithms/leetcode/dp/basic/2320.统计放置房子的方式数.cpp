/*
 * @lc app=leetcode.cn id=2320 lang=cpp
 *
 * [2320] 统计放置房子的方式数
 */

// @lc code=start
const int MOD = 1e9 + 7, MX = 1e4 + 1;
int f[MX] = {1, 2};
int init = []() {
    // f[i] 代表前i个地块的方案数
    for (int i = 2; i < MX; ++i)
        // 第i块：放或者不放
        f[i] = (f[i - 1] + f[i - 2]) % MOD;
    return 0;
}();

class Solution {
public:
    int countHousePlacements(int n) {
        return (long) f[n] * f[n] % MOD;
    }
};
// @lc code=end

