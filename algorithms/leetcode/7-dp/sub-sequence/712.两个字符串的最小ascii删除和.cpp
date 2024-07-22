/*
 * @lc app=leetcode.cn id=712 lang=cpp
 *
 * [712] 两个字符串的最小ASCII删除和
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();

        // 1. memo
        // vector<vector<int>> memo(n, vector<int>(m, -1));
        // function<int(int, int)> dfs = [&] (int i, int j){
        //     if(i < 0) {
        //         int sum = 0;
        //         for(int k = 0; k <= j; k++) {
        //             sum += s2[k];
        //         }
        //         return sum;
        //     }
        //     if(j < 0) {
        //         int sum = 0;
        //         for(int k = 0; k <= i; k++) {
        //             sum += s1[k];
        //         }
        //         return sum;
        //     }
        //     int &res = memo[i][j];
        //     if(res != -1) return res;
        //     if(s1[i] == s2[j])
        //         return res = dfs(i-1, j-1);
        //     return res = min(dfs(i, j-1) + s2[j], dfs(i-1, j) + s1[i]);
        // };
        // return dfs(n-1, m-1);


        // 2. dp
        // vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        // for(int i = 0; i < m; i++) {
        //     f[0][i+1] = f[0][i] + s2[i];
        // }
        // for(int i = 0; i < n; i++) {
        //     f[i+1][0] = f[i][0] + s1[i];
        //     for(int j = 0; j < m; j++) {
        //         f[i+1][j+1] = s1[i] == s2[j]
        //                         ? f[i][j]
        //                         : min(f[i+1][j] + s2[j], f[i][j+1] + s1[i]);
        //     }
        // }
        // return f[n][m];

        // 3. dp compression 2 array
        // vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        // for(int i = 0; i < m; i++) {
        //     f[0][i+1] = f[0][i] + s2[i];
        // }
        // for(int i = 0; i < n; i++) {
        //     f[(i+1)%2][0] = f[i%2][0] + s1[i];
        //     for(int j = 0; j < m; j++) {
        //         f[(i+1)%2][j+1] = s1[i] == s2[j]
        //                         ? f[i%2][j]
        //                         : min(f[(i+1)%2][j] + s2[j], f[i%2][j+1] + s1[i]);
        //     }
        // }
        // return f[n%2][m];

        // 4. dp compression 1 array
        vector<int> f(m+1, 0);
        for(int i = 0; i < m; i++) {
            f[i+1] = f[i] + s2[i];
        }
        for(int i = 0; i < n; i++) {
            int prev = f[0];
            f[0] += s1[i];
            for(int j = 0; j < m; j++) {
                int temp = f[j+1];
                f[j+1] = s1[i] == s2[j]
                                ? prev 
                                : min(f[j] + s2[j], f[j+1] + s1[i]);
                prev = temp;
            }
        }
        return f[m];
    }
};
// @lc code=end

