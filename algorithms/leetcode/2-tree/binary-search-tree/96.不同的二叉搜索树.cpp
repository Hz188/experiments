/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 */

// @lc code=start
#include <vector>

class Solution {
public:
    // 备忘录
    std::vector<std::vector<int>> memo;

    int numTrees(int n) {
        // 备忘录的值初始化为 0
        memo = std::vector<std::vector<int>>(n + 1, std::vector<int>(n + 1, 0));
        return count(1, n);
    }

private:
    int count(int lo, int hi) {
        if (lo > hi) return 1;
        // 查备忘录
        if (memo[lo][hi] != 0) {
            return memo[lo][hi];
        }

        int res = 0;
        for (int mid = lo; mid <= hi; mid++) {
            int left = count(lo, mid - 1);
            int right = count(mid + 1, hi);
            res += left * right;
        }
        // 将结果存入备忘录
        memo[lo][hi] = res;

        return res;
    }
};
// @lc code=end

