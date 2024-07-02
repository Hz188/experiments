/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 *
 * [3040] 相同分数的最大操作数目 II
 */

// @lc code=start
#include <vector>
#include <set>
#include <functional>
using namespace std;
class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        // 1. memo
        if(n == 1) return 0;
        if(n == 2) return 1;
        set<int> score{};
        score.insert(nums[0] + nums[1]);
        score.insert(nums[0] + nums[n-1]);
        score.insert(nums[n-2] + nums[n-1]);

        vector<vector<int>> memo;
        function<int(int, int, int)> dfs = [&] (int i, int j, int score) {
            if(i >= j) return 0;
            int& res = memo[i][j];
            if(i+1 == j) return res = (nums[i] + nums[j] == score);
            if(res != -1) return res;
            res = 0;
            if(nums[i] + nums[i+1] == score) {
                res = max(res, dfs(i+2, j, score) + 1);
            } 
            if(nums[j] + nums[j-1] == score) {
                res = max(res, dfs(i, j-2, score) + 1);
            } 
            if(nums[i] + nums[j] == score) {
                res = max(res, dfs(i+1, j-1, score) + 1);
            } 
            return res;
        };

        int res = 0;
        for(auto s: score) {
            memo = vector(n, vector<int>(n, -1));
            res = max(res, dfs(0, n-1, s));
        }
        // return res;

        // 1.1 看了0x3f题解，思路一致，写法更优雅，
        // int res1 = dfs(2, n-1, nums[0] + nums[1]);
        // int res2 = dfs(0, n-3, nums[n-2] + nums[n-1]);
        // int res3 = dfs(1, n-2, nums[0] + nums[n-1]);
        // return max({res1, res2, res3}) + 1;


        // 2. dp
        auto helper = [&](int start, int end, int target) {
            vector<vector<int>> f(n, vector<int>(n,  0));
            for (int i = end-1; i >= start; i--) {
                for (int j = i+1 ; j <= end; j++) {
                    if(i+1 == j) {
                        f[i][j] = (nums[i] + nums[j] == target);
                        continue;
                    }
                    if (nums[i] + nums[i + 1] == target) { // 删除前两个数
                        f[i][j] = max(f[i][j], f[i+2][j] + 1);
                    }
                    if (nums[j - 1] + nums[j] == target) { // 删除后两个数
                        f[i][j] = max(f[i][j], f[i][j-2] + 1);
                    }
                    if (nums[i] + nums[j] == target) { // 删除第一个和最后一个数
                        f[i][j] = max(f[i][j], f[i+1][j-1] + 1);
                    }
                }
            }
            return f[start][end];
        };
        int res1 = helper(2, n - 1, nums[0] + nums[1]); // 删除前两个数
        int res2 = helper(0, n - 3, nums[n - 2] + nums[n - 1]); // 删除后两个数
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1]); // 删除第一个和最后一个数
        return max({res1, res2, res3}) + 1; // 加上第一次操作

    }
};
// @lc code=end

