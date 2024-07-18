/*
 * @lc app=leetcode.cn id=739 lang=cpp
 *
 * [739] 每日温度
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n);
        stack<int> s{};
        for(int i = 0; i < n; i++) {
            while(!s.empty() && temperatures[s.top()] < temperatures[i]) {
                int j = s.top();
                res[j] = i - j;
                s.pop();
            }
            s.push(i);
        } 
        return res;
    }
};
// @lc code=end

