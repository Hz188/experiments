/*
 * @lc app=leetcode.cn id=583 lang=cpp
 *
 * [583] 两个字符串的删除操作
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    int minDistance(string word1, string word2) {

        int n = word1.length();
        int m = word2.length();

        // 1. memo
        // vector<vector<int>> memo(n, vector<int>(m, -1));
        // function<int(int, int)> dfs = [&] (int i, int j){
        //     if(i < 0) return j+1;
        //     if(j < 0) return i+1;
        //     int &res = memo[i][j];
        //     if(res != -1) return memo[i][j];
        //     if(word1[i] == word2[j])
        //         return res = dfs(i-1, j-1);
        //     return res = min(dfs(i, j-1), dfs(i-1, j)) + 1;
        // };
        // return dfs(n-1, m-1);


        // 2. dp
        // vector<vector<int>> f(n+1, vector<int>(m+1, -1));
        // for(int i = 0; i <= m; i++) {
        //     f[0][i] = i;
        // }
        // for(int i = 0; i < n; i++) {
        //     f[i+1][0] = i+1;
        //     for(int j = 0; j < m; j++) {
        //         f[i+1][j+1] = word1[i] == word2[j]
        //                         ? f[i][j]
        //                         : min(f[i+1][j], f[i][j+1]) + 1;
        //     }
        // }
        // return f[n][m];

        // 3. dp compression 2 array
        // vector<vector<int>> f(2, vector<int>(m+1, -1));
        // for(int i = 0; i <= m; i++) {
        //     f[0][i] = i;
        // }
        // for(int i = 0; i < n; i++) {
        //     f[(i+1)%2][0] = i+1;
        //     for(int j = 0; j < m; j++) {
        //         f[(i+1)%2][j+1] = word1[i] == word2[j]
        //                         ? f[i%2][j]
        //                         : min(f[(i+1)%2][j], f[i%2][j+1]) + 1;
        //     }
        // }
        // return f[n%2][m];

        // 4. dp compression 1 array
        vector<int> f(m+1, -1);
        for(int i = 0; i <= m; i++) {
            f[i] = i;
        }
        for(int i = 0; i < n; i++) {
            int prev = f[0];
            f[0]++;
            for(int j = 0; j < m; j++) {
                int temp = f[j+1];
                f[j+1] = word1[i] == word2[j]
                                ? prev
                                : min(f[j], f[j+1]) + 1;
                prev = temp;
            }
        }
        return f[m];
    }
};
// @lc code=end

