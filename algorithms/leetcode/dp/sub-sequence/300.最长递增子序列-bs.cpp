/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        vector<int> g;
        for (int x : nums) {
            auto it = ranges::lower_bound(g, x);
            if (it == g.end()) {
                g.push_back(x); // >=x 的 g[j] 不存在
            } else {
                *it = x;
            }
        }
        return g.size();
    }
};
// @lc code=end

