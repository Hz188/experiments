/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res{};
        vector<int> path{};
        vector<bool> used(n, false);
        function<void(int)> dfs = [&] (int i) {
            res.push_back(path);
            for(int j = i; j < n; j++) {
                if(j > 0 && nums[j] == nums[j-1] && !used[j-1]) continue;
                if(!used[j]) {
                    path.push_back(nums[j]);
                    used[j] = true;
                    dfs(j+1);
                    path.pop_back();
                    used[j] = false;

                }
            }
        };
        dfs(0);
        return res;
    }
};
// @lc code=end

