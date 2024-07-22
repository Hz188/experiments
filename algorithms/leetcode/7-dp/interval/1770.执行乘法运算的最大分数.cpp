/*
 * @lc app=leetcode.cn id=1770 lang=cpp
 *
 * [1770] 执行乘法运算的最大分数
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        int n = nums.size();
        int m = multipliers.size();
        vector<vector<vector<int>>> memo(n, vector<vector<int>>(n, vector<int>(m, -1)));
        function<int(int, int, int)> dfs = [&] (int i, int j, int op) { 
            if(op == m) return 0;
            int& res = memo[i][j][op];
            if(res != -1) return res;
            return res = max(
                    dfs(i+1, j, op+1) + nums[i] * multipliers[op],
                    dfs(i, j-1, op+1) + nums[j] * multipliers[op]
                    );
        };
        return dfs(0, n-1, 0);

    }
};
// @lc code=end

