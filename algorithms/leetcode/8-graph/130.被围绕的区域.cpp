/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        function<void(int, int)> dfs = [&] (int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != 'O') {
                return;
            }
            board[i][j] = 'A';
            dfs( i + 1, j);
            dfs( i - 1, j);
            dfs( i, j + 1);
            dfs( i, j - 1);


        };
        for(int i = 0; i < m; i++){
            dfs(i, 0);
            dfs(i, n-1);
        }
        for(int j = 0; j < n; j++) {
            dfs(0, j);
            dfs(m-1, j);
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A') {
                    board[i][j] = 'O';
                } else if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
            }
        }
    }
};
// @lc code=end

