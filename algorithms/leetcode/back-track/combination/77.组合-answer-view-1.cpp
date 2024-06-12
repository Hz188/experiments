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
        //[1...n] 中选k个
        // 从可选的数的角度做回溯
        // 正着选 + 剪枝
        function<void(int)> dfs = [&](int start) {
            int d = k - path.size(); // 需要选的个数

            // 位置1
            // if (d > n - start + 1) return;

            if(path.size() == k){
                ans.push_back(path);
                return;
            }

            // 位置2
            // for(int i = start; i <= n-d+1; i++) { //至少要给后面的递归留够 d-1 个选择
            for(int i = start; i <= n; i++) {
                // 位置3
                if(d > n - i + 1)  // i > n - d + 1 则return 也就是 i<=n-d+1
                    return;
                path.push_back(i);
                dfs(i+1);
                path.pop_back();
            }
        };
        // 倒序选 + 剪枝

        dfs(1);
        return ans;
    }
};
// @lc code=end

