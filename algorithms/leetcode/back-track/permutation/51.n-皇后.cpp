// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem51.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans{};
        vector<int> col(n), on_path(n), diag1(2*n-1), diag2(2*n-1);
        function<void(int)> dfs = [&](int r) {
            if(r == n){
                vector<string> board(n, string(n, '.')); 
                for(int i = 0; i < n; i++){
                    board[i][col[i]] = 'Q';
                } 
                ans.push_back(board);
                return;
            }
            for (int c = 0; c < n; ++c) {
                int rc = r - c + n - 1;
                if (!on_path[c] && !diag1[r + c] && !diag2[rc]) {
                    col[r] = c;
                    on_path[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    on_path[c] = diag1[r + c] = diag2[rc] = false;
                }
            }
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

