/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans{};
        vector<int> path{};
        function<void(int, int)> dfs = [&](int i, int t) {
            int d = k - path.size();//还需要选d个
            if(t < 0 || (i+i-d+1)*d/2 < t) return;
            if(d == 0) {
                ans.push_back(path);
                return;
            }

            if(i > d){  //可选数不够d个了，剪枝
                dfs(i-1, t);
            }
            path.push_back(i);
            dfs(i-1, t-i);
            path.pop_back();
        };
        dfs(9, n);
        return ans;
    }
};
// @lc code=end

