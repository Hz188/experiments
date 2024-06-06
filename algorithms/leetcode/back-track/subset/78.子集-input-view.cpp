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

    //输入视角
    void dfs(vector<int>& nums, int i, vector<int>& path, vector<vector<int>>& res){
        if(i == nums.size()) {
            res.push_back(path);
            return;
        }

        dfs(nums, i+1, path, res);//没选nums[i]
        path.push_back(nums[i]);
        dfs(nums, i+1, path, res);//选了nums[i]
        path.pop_back();
    }
    
};
// @lc code=end

