/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> res{};
        vector<int> path{};
        vector<int> used(n, false);
        function<void(int)> dfs = [&](int i) {
            if(path.size() == n) {
                res.push_back(path);
                return;
            }
            for(int j = 0; j < n; j++) {
                if(j > 0 && nums[j] == nums[j-1] && !used[j-1]) continue;
                if(!used[j]){
                    used[j] = true;
                    path.push_back(nums[j]);
                    dfs(j);
                    used[j] = false;
                    path.pop_back();
                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end

