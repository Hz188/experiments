/*
 * @lc app=leetcode.cn id=1911 lang=cpp
 *
 * [1911] 最大子序列交替和
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // 1. memo 
        // vector<vector<long long>> memo(n, vector<long long>(2, -1));
        // function<long long(int, int)> dfs = [&] (int i, int p) {
        //     if(i < 0) { //  i == -1
        //         return 0ll; 
        //     }
        //     auto& res = memo[i][p];
        //     if(res != -1) return res;
        //     if(p == 0) 
        //         return res = max(dfs(i-1, 0), dfs(i-1, 1) - nums[i]);
        //     // zero_or_one == 1
        //     return res = max(dfs(i-1, 1), dfs(i-1, 0) + nums[i]);
        // };
        // return dfs(n-1, 1);

        // 超时了 memo


        // 2. dp 
        // vector<vector<long long>> f(n+1, vector<long long>(2, 0));
        // for(int i = 0; i < n; i++) {
        //     f[i+1][0] = max(f[i][0], f[i][1] - nums[i]);
        //     f[i+1][1] = max(f[i][1], f[i][0] + nums[i]);
        // }
        // return f[n][1];


        // 3. dp compression
        vector<long long> f(2, 0);
        for(int i = 0; i < n; i++) {
            long long temp = f[0];
            f[0] = max(f[0], f[1] - nums[i]);
            f[1] = max(f[1], temp + nums[i]);
        }
        return f[1];



    }
};
// @lc code=end



/*
 // 定义 dfs(i, p) 表示 nums[:i] 以 i 结尾，为子序列奇数/偶数(p = 0/1) 的最大交替和
    // 转移
    //   如果i接在子序列上
    //      如果 i 为子序列奇数尾  dfs(i, 0) = dfs(i-1, 1) - nums[i]
    //      如果 i 为子序列偶数尾  dfs(i, 1) = dfs(i-1, 0) + nums[i]
    //   如果i不接在子序列上
    //      如果 i 为子序列奇数尾  dfs(i, 0) = dfs(i-1, 0)
    //      如果 i 为子序列偶数尾  dfs(i, 1) = dfs(i-1, 1)
    //  取最大值，即
    //      dfs(i, 0) = max(dfs(i-1, 0), dfs(i-1, 1) - nums[i])
    //      dfs(i, 1) = max(dfs(i-1, 1), dfs(i-1, 0) + nums[i])
    // 递归边界：dfs(i < 0, p) = 0 
    // 递归入口：dfs(n-1, p) for p in range(2)

*/