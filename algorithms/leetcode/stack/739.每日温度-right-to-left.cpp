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
        for(int i = n-1; i>= 0; --i) {
            while(!s.empty() && temperatures[s.top()] <= temperatures[i])
                s.pop();
            res[i] = s.empty()? 0: s.top() - i;
            s.push(i);
        } 
        return res;
    }
};
// @lc code=end

