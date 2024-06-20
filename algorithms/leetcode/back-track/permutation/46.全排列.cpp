/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        vector<int> path{}, on_path(n);
        function<void(int)> dfs = [&](int i) {  // dfs(i) means 构造>=i部分的排列
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            for (int j = 0; j < n; ++j) {
                if (!on_path[j]) {
                    path.push_back(nums[j]);
                    on_path[j] = true;
                    dfs(i + 1);
                    path.pop_back();
                    on_path[j] = false; // 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

