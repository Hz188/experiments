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
            int x = nums[i];
            int l = 0, r = i-1;
            // 两个优化：需要倒序枚举i
            // 优化1: 最小的两个和都大于最大，那么任选[0...i]中的3个都满足 C(i+1, 3)
            // 优化2: 最大的两个都小，那么剩下的肯定都小
            /*
            if(nums[0] + nums[1] > x) {
                ans += (i+1) * i * (i-1) / 6;
                break;
            }
            if(nums[i-2] + nums[i-1] < x) {
                continue;
            }
            */
            while(l < r) {
                if(nums[l] + nums[r] > x){
                    // l 和 r 满足了，那么 l+1 ... r-1 和 r 肯定也满足，因为有序
                    ans += r-l;  // (r-1) - l + 1 = r - l
                    r--;
                } else {
                    // l  + r 不满足，那么 l和 r-1 r-2 ... l+1肯定也不满足，因为有序
                    l++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end

