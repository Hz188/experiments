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
        function<void(int, int)> dfs = [&](int n, int start) {
            if(path.size() == k){
                ans.push_back(path);
                return;
            }
            for(int i = start; i <= n; i++) {
                if(k - path.size() > n - i + 1)
                    return;
                path.push_back(i);
                dfs(n, i+1);
                path.pop_back();
            }
        };
        // 从选或不选的角度做回溯
        function<void(int, int)> dfs_2 = [&](int n, int start) {
            if(path.size() == k) { 
                ans.push_back(path);
                return;
            }
            if(n - start + 1 > k - path.size())
                dfs_2(n, start+1);

            path.push_back(start);
            dfs_2(n, start+1);
            path.pop_back();

        };

        // dfs(n, 1);
        dfs_2(n, 1);
        return ans;
    }
};
// @lc code=end

