/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        int ans {0};
        stack<int> s{};
        int n = height.size();
        for(int i = 0; i < n; i++) {
            while (!s.empty() && height[i] > height[s.top()]) {
                int bottom_h = height[s.top()];
                s.pop();
                if (s.empty()) break;
                int left = s.top();
                int height_diff = min(height[i], height[left]) - bottom_h;
                ans += height_diff * (i - left - 1);
            }
            s.push(i);
        }
        return ans;
    }
};
// @lc code=end

