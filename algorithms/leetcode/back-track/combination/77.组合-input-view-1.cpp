/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */

// @lc code=start
#include <functional>
#include <vector>
using namespace std;;
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans{};
        vector<int> path{};
        // 从选或不选的角度做回溯
        function<void(int)> dfs = [&](int i) {
            int d = k - path.size();

            if(d == 0) { 
                ans.push_back(path);
                return;
            }
            if(n - i + 1 > d)
                dfs(i + 1);

            path.push_back(i);
            dfs(i + 1);
            path.pop_back();

        };

        dfs(1);
        return ans;
    }
};
// @lc code=end

