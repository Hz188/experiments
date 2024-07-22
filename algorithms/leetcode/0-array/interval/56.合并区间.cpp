/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [] (auto& a, auto& b) {
            return a[0] < b[0];
        });
        vector<vector<int>> res{};
        res.push_back(intervals[0]);
        for(int i = 1; i < n; ++i) {
            auto& cur = intervals[i];
            auto& last = res.back();
            if(cur[0] <= last[1]){
                last[1] = max(last[1], cur[1]);
            } else {
                res.push_back(cur);
            }
        }
        return res;
    }
};
// @lc code=end

