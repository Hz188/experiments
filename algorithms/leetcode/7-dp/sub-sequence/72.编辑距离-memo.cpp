/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int minDistance(string s, string t) {
        int n = s.size();
        int m = t.size();
        // 1. memo
        // vector<vector<int>> memo(n, vector<int>(m, -1));
        // function<int(int, int)> dfs = [&](int i, int j) {
        //     if(i < 0) return j+1;
        //     if(j < 0) return i+1;
        //     int& res = memo[i][j];
        //     if(res != -1) return memo[i][j];
        //     if(s[i] == t[j])
        //         return res = dfs(i-1, j-1);
        //     return res = min(dfs(i-1, j), min(dfs(i, j-1), dfs(i-1, j-1))) + 1;
        // };
        // return dfs(n-1, m-1);

        // 2. dp
        // vector<vector<int>> f(n+1, vector<int>(m+1, 0));
        // for(int j = 0; j <= m; ++j){
        //     f[0][j] = j; // base case 1
        // }
        // for(int i = 0; i < n; ++i) {
        //     f[i+1][0] = i+1; // base case 2
        //     for(int j = 0; j < m; ++j) {
        //         f[i+1][j+1] = s[i] == t[j] ? f[i][j]: 
        //             min(f[i][j+1], min(f[i+1][j], f[i][j])) + 1;
        //     }
        // }
        // return f[n][m];
        // 3. dp compression 2 arrya
        // vector<vector<int>> f(2, vector<int>(m+1, 0));
        // for(int j = 0; j <= m; ++j){
        //     f[0][j] = j; // base case 1
        // }
        // for(int i = 0; i < n; ++i) {
        //     f[(i+1) % 2][0] = i+1; // base case 2
        //     for(int j = 0; j < m; ++j) {
        //         f[(i+1)%2][j+1] = s[i] == t[j] ? f[i%2][j]: 
        //             min(f[i%2][j+1], min(f[(i+1)%2][j], f[i%2][j])) + 1;
        //     }
        // }
        // return f[n%2][m]; 
        // 4. dp compression 1 array
        vector<int> f(m+1, 0);
        for(int j = 0; j <= m; ++j){
            f[j] = j; // base case 1
        }
        for(int i = 0; i < n; ++i) {
            // f[i+1][0] = i+1; // base case 2
            int prev = f[0];
            f[0]++;
            for(int j = 0; j < m; ++j) {
                int temp = f[j+1];
                f[j+1] = s[i] == t[j]  // f[i+1][j+1]
                                ? prev // f[i][j]
                                : min(f[j+1], min(f[j], prev)) + 1;
                prev = temp;
            }
        }
        return f[m];
    }
};
// @lc code=end

