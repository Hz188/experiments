/*
 * @lc app=leetcode.cn id=503 lang=cpp
 *
 * [503] 下一个更大元素 II
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        stack<int> s{};
        for(int i = 0; i < n * 2; i++) {
            while(!s.empty() && nums[s.top() % n] < nums[i % n]) {
                int j = s.top();
                res[j%n] = nums[i%n];
                s.pop();
            }
            s.push(i);
        } 
        return res;
    }
};
// @lc code=end

