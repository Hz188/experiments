/*
 * @lc app=leetcode.cn id=1109 lang=cpp
 *
 * [1109] 航班预订统计
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int> diff(n, 0);
        for(auto& booking : bookings) {
            int i = booking[0] - 1;
            int j = booking[1] - 1;
            int val = booking[2];
            diff[i] += val;
            if(j+1 < n) {
                diff[j+1] -= val;
            }
        }
        vector<int> res(n);
        res[0] = diff[0];
        for(int i = 1; i < n; i++) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};
// @lc code=end

