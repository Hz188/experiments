/*
 * @lc app=leetcode.cn id=1288 lang=cpp
 *
 * [1288] 删除被覆盖区间
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [] (auto& a, auto& b) {
            return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
            // 起点升序，终点降序 = 长的那个区间在上面（按照终点降序）
        });

        int left = intervals[0][0];
        int right = intervals[0][1];
        
        int res = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            auto& intv = intervals[i];
            // case 1. 覆盖
            if(left <= intv[0] && right >= intv[1]) {
                res++;
            }
            // case 2. 相交
            if(left <= intv[0] && right <= intv[1]) {
                right = intv[1];
            }
            // case 3. 无关
            if(right < intv[0]) {
                left = intv[0];
                right = intv[1];
            }
        }
        return intervals.size() - res;

    }
};
// @lc code=end

