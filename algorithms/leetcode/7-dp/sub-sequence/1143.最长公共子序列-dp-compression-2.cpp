/*
 * @lc app=leetcode.cn id=1143 lang=cpp
 *
 * [1143] 最长公共子序列
 */

// @lc code=start
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<int> dp(m+1, 0);
        for(int i = 0; i < n; ++i) {
            int prev = dp[0]; // [i][0]
            for(int j = 0; j < m; ++j) {
                int tmp = dp[j+1]; // [i][j+1]
                dp[j+1] = s[i] == t[j]? prev +1 : max(dp[j+1], dp[j]); // [i+1][j+1]
                prev = tmp; 
            }
        }
        return dp[m];
        /* 启发思路是如此的
            i的每次更新意味着换行了，j的每次更新意味着行内的下一个元素了
            从prev初始化的位置，然后进入j=0，来辅助思考
            这个时候，初始化prev相当于上一行的第0个元素，也就是左上角
                进入循环时，
                要更新当前行 i 行，dp[j+1]，所以未更新时dp[j+1]隐含了[i-1]
                prev的更新是tmp，是未更新的dp[j+1]隐含了[i-1]
                    进入下一个loop(j)的时候，相对于当前的j+1就成为了dp[i-1][j]了，也就是左上角
            注意prev初始化的位置是loop(i)
                i的循环意味着什么？意味着要更新下一行了，这个时候int prev相当于是记录了下一行的第一个左上角
            再注意prev更新的位置是loop(j)
                loop(j)内，这个时候记着每次维护prev的语义（循环不变量）
        */
    }
};
// @lc code=end

