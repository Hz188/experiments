/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        // 当前选择: s3[k] 是 s1[i] 或者 s2[j]
        // 当前子问题： s3[...k] 由 s1[...i] s2[...j]交错
        // 下一个子问题 s3[...k-1] 由
        //                        s1[...i] s2[...j-1]交错
        //                        s1[...i-1] s2[...j]交错
        int n = s1.length();
        int m = s2.length();
        int l = s3.length();
        if((n + m) != l) return false;

        // 1. memo 
        // vector<vector<vector<int>>> memo(l, vector<vector<int>>(n, vector<int>(m, -1)));
        // function<int(int, int, int)> dfs = [&] (int i, int j, int k) {
            
        //     if(i < 0) return s2.substr(0, j+1) == s3.substr(0, k+1) ? 1: 0;
        //     if(j < 0) return s1.substr(0, i+1) == s3.substr(0, k+1) ? 1: 0;
        //     int& res = memo[k][i][j];
        //     if(res != -1)
        //         return res;
        //     bool f1 = s1[i] == s3[k];
        //     bool f2 = s2[j] == s3[k];
        //     if(f1 && !f2) {
        //         return res = dfs(i-1, j, k-1); 
        //     }else if(!f1 && f2) {
        //         return res = dfs(i, j-1, k-1); 
        //     }else if(f1 && f2) {
        //         return res = dfs(i-1, j, k-1) || dfs(i, j-1, k-1); 
        //     } else {
        //         return res = 0;
        //     }
        // };
        // return dfs(n-1, m-1, l-1);

        // 1.1 memo 看了题解优化了一下上面我自己写的if判断逻辑
        // vector<vector<int>> memo(n, vector<int>(m, -1));
        // function<int(int, int)> dfs = [&] (int i, int j) {
        //     int k = i + j + 1;
        //     if(i < 0) return s2.substr(0, j+1) == s3.substr(0, k+1) ? 1: 0;
        //     if(j < 0) return s1.substr(0, i+1) == s3.substr(0, k+1) ? 1: 0;
        //     int& res = memo[i][j];
        //     if(res != -1)
        //         return res;
        //     bool f1 = s1[i] == s3[k];
        //     bool f2 = s2[j] == s3[k];
        //     return res = (dfs(i-1, j) && f1) || (dfs(i, j-1) && f2);
        // };
        // return dfs(n-1, m-1);

        // 2. dp
        // vector<vector<bool>> f(n+1, vector<bool>(m+1, false));
        // f[0][0] = true; // 特殊情况 空和空交错出空
        // for(int i = 0; i < m; i++) {
        //     f[0][i+1] = s2.substr(0, i+1) == s3.substr(0, i+1);
        // }
        // for(int i = 0; i < n; i++) {
        //     f[i+1][0] = s1.substr(0, i+1) == s3.substr(0, i+1);
        //     for(int j = 0; j < m; j++) {
        //         int k = i + j + 1;
        //         f[i+1][j+1] = ((f[i+1][j] && s2[j]== s3[k]) || (f[i][j+1] && s1[i] == s3[k]));
        //     } 
        // }
        // return f[n][m];

        // 3. dp compression 2 array
        // vector<vector<bool>> f(2, vector<bool>(m+1, false));
        // f[0][0] = true; // 特殊情况 空和空交错出空
        // for(int i = 0; i < m; i++) {
        //     f[0][i+1] = s2.substr(0, i+1) == s3.substr(0, i+1);
        // }
        // for(int i = 0; i < n; i++) {
        //     f[(i+1)%2][0] = s1.substr(0, i+1) == s3.substr(0, i+1);
        //     for(int j = 0; j < m; j++) {
        //         int k = i + j + 1;
        //         f[(i+1)%2][j+1] = ((f[(i+1)%2][j] && s2[j]== s3[k]) || (f[i%2][j+1] && s1[i] == s3[k]));
        //     } 
        // }
        // return f[n%2][m];

        // 4. dp compression 1 array
        vector<bool> f(m+1, false);
        f[0] = true; // 特殊情况 空和空交错出空
        for(int i = 0; i < m; i++) {
            f[i+1] = s2.substr(0, i+1) == s3.substr(0, i+1);
        }
        for(int i = 0; i < n; i++) {
            f[0] = s1.substr(0, i+1) == s3.substr(0, i+1);
            for(int j = 0; j < m; j++) {
                int k = i + j + 1;
                int temp = f[j+1];
                f[j+1] = ((f[j] && s2[j]== s3[k]) || (f[j+1] && s1[i] == s3[k]));
            } 
        }
        return f[m];


    }
};
// @lc code=end

