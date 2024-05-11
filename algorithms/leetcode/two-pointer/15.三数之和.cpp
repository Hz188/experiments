/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res{};
        for(int i = 0; i < n-2; i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            // 2个小优化
            // i, i+1, i+2 > 0 直接break l往后都大于0
            // i, n-1, n-2 < 0 直接break r往前都小于0
            int l = i + 1, r = n - 1;
            while(l < r) {
                int sum = nums[l] + nums[r] + nums[i];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < r && nums[l] == nums[l-1]) l++;
                    r--;
                    while(r > l && nums[r] == nums[r+1]) r--;
                } else if(sum > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};
// @lc code=end

