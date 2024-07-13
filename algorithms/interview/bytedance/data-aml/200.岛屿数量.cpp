/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        function<void(int, int)> dfs = [&] (int i, int j) {
            if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == '0') {
                return;
            }
            grid[i][j] = '0';
            dfs(i-1, j);
            dfs(i, j-1);
            dfs(i+1, j);
            dfs(i, j+1);
        };
        int res = 0;
        for(int i = 0; i < m; ++i) {
            for(int j = 0; j < n; ++j) {
                if(grid[i][j] == '1') {
                    res += 1;
                    dfs(i, j);
                }
            }
        }
        return res;
        
    }
};
// @lc code=end

