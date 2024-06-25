/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<int> memo(amount+1, -666);
        function<int(int)> dfs = [&](int amount) -> int {
            if(amount == 0) return 0;
            if(amount < 0) return -1;
            if(memo[amount] != -666) return memo[amount];
            int res = INT_MAX;
            for(int c: coins){
                int sub_problem = dfs(amount - c);
                if(sub_problem == -1) continue;
                res = min(res, sub_problem+1);
            }
            memo[amount] = res == INT_MAX ? -1 : res;
            return memo[amount];
        };
        return dfs(amount);
    }
};
// @lc code=end

