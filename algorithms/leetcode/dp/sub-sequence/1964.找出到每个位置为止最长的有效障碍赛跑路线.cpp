/*
 * @lc app=leetcode.cn id=1964 lang=cpp
 *
 * [1964] 找出到每个位置为止最长的有效障碍赛跑路线
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        int n = obstacles.size();
        // 超时
        // vector<int> f(n, 1);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < i; j++) {
        //         if(obstacles[i] >= obstacles[j]){
        //             f[i] = max(f[j] + 1, f[i]);
        //         }
        //     }
        // }
        // return f;
        // 二分
        vector<int> g;
        vector<int> res;
        for (int x : obstacles) {
            auto it = ranges::upper_bound(g, x);
            if (it == g.end()) {
                g.push_back(x); // >=x 的 g[j] 不存在
                res.push_back(g.size());
            } else {
                *it = x;
                res.push_back(it - g.begin() + 1);
            }
        }
        return res;
    }
};
// @lc code=end

