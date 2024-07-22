/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
class Solution {
public:
    int fib(int n) {
        if(n < 2){
            return n;
        }
        int f0 = 0, f1 = 1;
        int res;
        for(int i = 2; i <= n; i++) {
            res = f0 + f1;
            f0 = f1;
            f1 = res;
        }
        return res;
    }
};
// @lc code=end

