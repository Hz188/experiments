/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */

// @lc code=start
#include <vector>
#include <functional>
#include <numeric>
using namespace std;
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(sum % 2 != 0) return false;
        int capacity = sum / 2;
        vector<vector<int>> memo(n, vector<int>(capacity+1, -1));
        function<bool(int, int)> dfs = [&] (int i, int c) -> bool {
            if(i < 0) 
                return c == 0;
            int& res = memo[i][c];
            if(res != -1) return res;
            if(c < nums[i]) return res = dfs(i-1, c);
            return res = dfs(i-1, c) || dfs(i-1, c - nums[i]);
        };
        return dfs(n-1, capacity);

        // 2. 递推 3. 两个数组 4. 一个数组
        //全是重复代码，参考 0-1背包
    }
};
// @lc code=end

