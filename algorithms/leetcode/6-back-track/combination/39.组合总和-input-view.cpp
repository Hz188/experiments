/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans{};
        vector<int> path{};

        function<void(int, int)> dfs = [&] (int i, int t) {
            if(t == 0) {
                ans.push_back(path);
                return;
            }

            if(i >= n) return;  //位置1
            if (t < candidates[i]) return; //排序后剪枝

            //不选
            // if(i < n-1)  //位置2
                dfs(i+1, t);
            //选
            path.push_back(candidates[i]);
            dfs(i, t-candidates[i]);
            path.pop_back();
        };
        dfs(0, target);
        return ans;
    }
};
// @lc code=end

