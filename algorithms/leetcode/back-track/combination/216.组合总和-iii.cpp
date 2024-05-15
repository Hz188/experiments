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
        function<void(int, int)> dfs = [&](int i, int sum) {
            if(sum == 0 && path.size() == k) {
                ans.push_back(path);
                return;
            }
            int d = k - path.size();//还需要选d个
            if((9 + 9-d+1) * d / 2 < sum) //可选的数中d个最大的都不够sum，剪枝
                return;
            if(sum - i < 0)// 选最小的都让sum-i小于0了，也剪枝
                return;

            if(9 - i + 1 > d){  //可选数不够d个了，剪枝
                dfs(i+1, sum);
            }
            path.push_back(i);
            dfs(i+1, sum-i);
            path.pop_back();
        };
        dfs(1, n);
        return ans;
    }
};
// @lc code=end

