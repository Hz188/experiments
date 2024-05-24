/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for(int i = 2; i < n; ++i) {
            //两个优化
            int x = nums[i];
            int l = 0, r = i-1;
            while(l < r) {
                if(nums[l] + nums[r] > x){
                    ans += r-l;
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

