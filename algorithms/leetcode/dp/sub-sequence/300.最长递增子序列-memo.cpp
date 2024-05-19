/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        vector<int> memo(n, -1);
        function<int(int)> dfs = [&](int i) -> int {
            if(i < 0) return 0;
            int& res = memo[i];
            if(memo[i] != -1) return memo[i];
            int sub_problem = 0;
            for(int j = 0; j < i; ++j){
                if(nums[i] > nums[j])
                    sub_problem = max(sub_problem, dfs(j));
            }
            return memo[i] = sub_problem + 1;
        };
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans = max(ans, dfs(i));
        }
        return ans;
    }
};
// @lc code=end

