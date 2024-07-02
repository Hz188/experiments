/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:

    int minCut(string s) {
        return minCut_ghz(s);
    }
    int minCut_dp(string s) {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        vector<int> f(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (g[0][i]) { // s[0...i] 是回文，无需分割
                f[i] = 0;
            }
            else {
                for (int j = 0; j < i; ++j) { // s[0...i]不是回文串，那么找分割点
                    if (g[j + 1][i]) { // s[j+1...i] 是回文串，那么f[i] 就等于 f[j]需要切分的次数 加上 1（j和j+1这切一次）
                        f[i] = min(f[i], f[j] + 1); // 不同的切分点，选最小值
                    }
                }
            }
        }
        return f[n - 1];
    }

    int minCut_ghz(string s) {
        int n = s.size();
        vector<vector<int>> g(n, vector<int>(n, true));

        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        } // 提前记录g[i][j] = s[i..j]是不是回文串
        // vector<vector<int>> memo(n, vector<int>(n, -1));
        // function<int(int, int)> dfs = [&] (int i, int j) { // dfs(i, j) 分割[i...j]需要的最小次数
        //     if(i == j) return 0;
        //     int& res = memo[i][j];
        //     if(res != -1) return res; 
        //     if(g[i][j]) return res = 0; // 是回文串则无需分割
        //     else { // 不是回文串，进行分割，遍历可能得分割点，
        //         res = INT_MAX;
        //         for(int k = i; k < j; k++){
        //              res =  min(dfs(i, k) + dfs(k+1, j) + 1, res);  // 我自己的写法 超时了
        //              if(g[k+1]j])
        //                  res = min(dfs(i, k) + 1, res); // 看了答案改进后就通过了
        //         }
        //         return res;
        //     }
        // };
        // return dfs(0, n-1);  //自己的写法 超时了

        vector<int> memo(n, -1);
        function<int(int)> dfs = [&] (int i) {
            if(i == 0) return 0;
            int& res = memo[i];
            if(res != -1) return res;
            if(g[0][i])
                return res = 0;
            else {
                res = INT_MAX;
                for(int j = 0; j < i; j++) {
                    if(g[j+1][i])
                        res = min(dfs(j) + 1, res);
                }
                return res;
            }
        };
        return dfs(n-1);
        
    }

};
// @lc code=end

