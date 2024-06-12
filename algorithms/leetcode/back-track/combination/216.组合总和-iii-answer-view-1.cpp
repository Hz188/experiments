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
            int d = k - path.size();

            if (t < 0 
                || (9+9-d+1)*d/2 < t)
                return;
            // 注意 如果d==0，代入上面的if发现 是 t<0 || t>0 如果是false 即 t == 0

            if(d == 0){  // 所以这里不需要判断 t == 0了
                ans.push_back(path);
                return;
            }
            // if (d > 9 - i + 1) return;  //位置1

            // 位置2
            // for(int j = i; j <= 9-d+1; j++) { //至少要给后面的递归留够 d-1 个选择
            for(int j = i; j <= 9; j++) {
                // 位置3
                if(d > 9 - i + 1)  // i > n - d + 1 则return 也就是 i<=n-d+1  
                    return;
                path.push_back(j);
                dfs(j+1, t-j);
                path.pop_back();
            }
        };

        dfs(1, n);
        return ans;
    }
};
// @lc code=end

