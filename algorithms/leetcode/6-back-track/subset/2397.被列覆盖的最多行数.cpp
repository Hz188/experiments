/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */

// @lc code=start
#include <vector>
#include <functional>
#include <unordered_map>
#include <unordered_set>
using namespace  std;
class Solution {
public:
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        int ans = 0;
        int m = matrix.size();
        int n = matrix[0].size();

        unordered_map<int, vector<int>> one_indices{};
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] == 1)
                    one_indices[i].push_back(j);
            }
        }
        unordered_set<int> path{};
        function<void(int)> dfs = [&] (int i) {
            if(path.size() == numSelect) {
                int cur = 0;
                for(int i = 0; i < m; i++) {
                    bool flag = true;
                    if(one_indices[i].size() > numSelect) continue;
                    for(int col: one_indices[i]){
                        if(!path.contains(col)) {
                            flag = false;
                            break;
                        }
                    }
                    cur += flag;
                }
                ans = max(ans, cur);
                return;
            } 

            if(i == n) return;

            dfs(i+1);

            path.insert(i);
            dfs(i+1);
            path.erase(i);
        };
        dfs(0);
        return ans;
    }
};
// @lc code=end

