/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) {
        bool flag{0};
        // method 1.前缀最大值，后缀最大值 O(n)
        // method 2.双指针
        return flag ? solve_1(height) : solve_2(height);
    }
private:
    int solve_1(vector<int>& height) {
        int n  = height.size();
        vector<int> pre_max(n, 0);
        pre_max[0] = height[0];
        for(int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i-1], height[i]);
        }
        vector<int> post_max(n, 0);
        post_max[n-1] = height[n-1];
        for(int i = n-2; i >= 0; i--) {
            post_max[i] = max(post_max[i+1], height[i]);
        }
        int res = 0;
        for(int i = 0; i < n; i++) {
            res += min(pre_max[i], post_max[i]) - height[i];
        }
        return res;
    }
    int solve_2(vector<int>& height) {
        int n = height.size();
        int res = 0;
        int left = 0, right = n-1;
        int pre_max = 0;
        int suf_max = 0;
        //left 和right的移动规则是，谁的max小谁移动
        while(left <right) { // left == right的情况是，顶峰相见了，一滴水都装不下
            pre_max = max(pre_max, height[left]);
            suf_max = max(suf_max, height[right]);
            if(pre_max < suf_max) {
                res += pre_max - height[left];
                left++;
            } else {
                res += suf_max - height[right];
                right--;
            }
        }
        return res;
    }

};
// @lc code=end

