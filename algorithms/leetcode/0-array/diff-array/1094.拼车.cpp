/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 *
 * [1094] 拼车
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<int> diff(1001, 0);

        for(auto& trip: trips) {
            int val = trip[0];
            int i = trip[1];
            int j = trip[2] - 1;
            diff[i] += val;
            diff[j+1] -= val;
        }
        vector<int> res(1001, 0);
        res[0] = diff[0];
        if (res[0] > capacity) return false;
        for(int i = 1; i < res.size(); i++) {
            res[i] = res[i-1] + diff[i];
            if(res[i] > capacity) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

