/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int totalNQueens(int n) {
        int ans{};
        vector<int> col(n), on_path(n), diag1(2*n-1), diag2(2*n-1);
        function<void(int)> dfs = [&](int r) {
            if(r == n){
                ans++;
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

