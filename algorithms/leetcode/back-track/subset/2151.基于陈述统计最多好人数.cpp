/*
 * @lc app=leetcode.cn id=2151 lang=cpp
 *
 * [2151] 基于陈述统计最多好人数
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int maximumGood(vector<vector<int>> &statements) {
        int ans = 0, n = statements.size();
        for (int i = 1; i < 1 << n; ++i) {  // 范围是[0, 2^n-1] 也就是 i<= 2^n-1 < 2^n = 1 << n
            int cnt = 0; // i 中好人个数
            for (int j = 0; j < n; ++j) {  // n个二进制位 0到n-1 分别枚举
                if ((i >> j) & 1) { // (i>>j) & 1 相当于取出 i 的二进制的第 j 位，也就是枚举 i 中的好人 j
                    for (int k = 0; k < n; ++k) { // 再枚举 j 的所有陈述
                        if (statements[j][k] < 2 //2表示没有陈述，所以小于2才有效
                            && statements[j][k] != ((i >> k) & 1)) { // 陈述与实际情况矛盾
                            goto next;
                        }
                    }
                    ++cnt;
                }
            }
            ans = max(ans, cnt);
            next:;
        }
        return ans;
    }
};
// @lc code=end

