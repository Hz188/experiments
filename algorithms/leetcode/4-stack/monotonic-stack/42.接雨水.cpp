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
            //整体遍历逻辑是
            //  单调栈元素是越来越小的
            //  那么现在当前 i，找了一个比栈顶大的，因为栈单调性，次顶也大于栈顶
            //  所以就找到了一个“两高夹一低”的区域，就可以计算出可存的雨水了
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

