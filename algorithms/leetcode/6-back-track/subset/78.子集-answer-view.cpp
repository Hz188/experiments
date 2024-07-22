/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        dfs(nums, 0, path, res);
        return res;
    }

    //答案视角
    void dfs(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& res) {
        res.push_back(path);

        for(int j = i; j < nums.size(); j++) {
            path.push_back(nums[j]);
            dfs(nums, j+1, path, res);
            path.pop_back();
        }
    }
};
// @lc code=end

