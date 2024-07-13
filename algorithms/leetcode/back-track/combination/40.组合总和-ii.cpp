/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res{};
        vector<int> path{};

        function<void(int, int)> dfs = [&] (int i, int t) {
            if(t == 0) {
                res.push_back(path);
                return;
            }
            if (i == n || t < candidates[i]) {  //排序后剪枝
                return;
            }
            for(int j = i; j < n; j++) {
                if(j > i && candidates[j] == candidates[j-1]) continue;
                path.push_back(candidates[j]);
                dfs(j+1, t - candidates[j]);
                path.pop_back();
            }
        };
        dfs(0, target);
        return res;


    }
};
// @lc code=end

