/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long l = 1; // min time cost
        long long min_time = *min_element(time.begin(), time.end());
        long long r = totalTrips * min_time;// max time cost
        // t = 1,2,3,...
        // trips_now = sum(t / time[i] for time[i] in time)
        // compare with trips_total
        while(l <= r) {
            auto mid = (r - l) / 2 + l;
            long long t = 0;
            for(auto& bus_time: time){
                t += mid / bus_time;
            }
            if(t < totalTrips) {
                l = mid + 1;
            } else { // t >= totalTrips
                r = mid - 1;
            }
        }
        // red  [...left-1]
        // blue [right+1...]
        // l  = r + 1
        return l;
    }
};
// @lc code=end

