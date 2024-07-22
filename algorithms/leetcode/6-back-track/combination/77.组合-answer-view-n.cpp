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
        // 反着选 + 剪枝
        function<void(int)> dfs = [&](int i) {
            int d = k - path.size(); // 需要选的个数

            // 位置1
            // if (i < d) return;

            if(path.size() == k){
                ans.push_back(path);
                return;
            }

            // 位置2
            // for(int j = i; j >= d; j--) { // 至少要够d个选择 
            for(int j = i; j >= 1; j--) {
                // 位置3
                if(j < d)  // j < d 也就是 j>=d
                    return;
                path.push_back(j);
                dfs(j-1);
                path.pop_back();
            }
        };

        dfs(n);
        return ans;
    }
};
// @lc code=end

