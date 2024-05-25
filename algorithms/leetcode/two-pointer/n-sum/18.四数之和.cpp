// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem18.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans{};
        for(int i = 0; i < n-3; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            for(int j = i+1; j < n-2; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;
                int l = j + 1;
                int r = n - 1;
                while(l < r) {
                    long long sum = (long)nums[i] + (long)nums[j] + nums[l] + nums[r];
                    if(sum < target) {
                        l++;
                    } else if(sum > target) {
                        r--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++, r--;
                        while(l < r & nums[l] == nums[l-1]) l++;
                        while(r > l & nums[r] == nums[r+1]) r--;
                    }
                }
            }
        }
        return ans;
    }
};
// @lc code=end

