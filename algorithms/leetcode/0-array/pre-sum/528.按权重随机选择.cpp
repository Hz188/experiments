/*
 * @lc app=leetcode.cn id=528 lang=cpp
 *
 * [528] 按权重随机选择
 */

// @lc code=start
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
class Solution {
private:
    vector<int> pre_sum{};
public:
    Solution(vector<int>& w) {
        pre_sum = vector<int>(w.size() + 1, 0);
        int n  = w.size();
        for(int i = 0; i < n; i++) {
            pre_sum[i+1] = pre_sum[i] + w[i];
        }
    }

    
    int pickIndex() {
        int n = pre_sum.size();
        int c = rand() % pre_sum.back() + 1; // [0...sum-1] -> [1...sum]
        auto id = lower_bound(pre_sum.begin(), pre_sum.end(), c);
        return id - pre_sum.begin() - 1;

    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
// @lc code=end

