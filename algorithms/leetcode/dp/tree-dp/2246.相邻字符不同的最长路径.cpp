/*
 * @lc app=leetcode.cn id=2246 lang=cpp
 *
 * [2246] 相邻字符不同的最长路径
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    int longestPath(vector<int> &parent, string &s) {
        // DP求树的直径的模板
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; ++i)
            g[parent[i]].push_back(i);

        int ans = 0;
        function<int(int)> dfs = [&](int x /*, int fa*/) -> int {
            int maxLen = 0;
            for (int y : g[x]) {
                // if y == fa: continue //如果题目说邻居包括了父节点
                int len = dfs(y) + 1;  // dfs(y, x)
                if (s[y] != s[x]) {  //这题相邻节点要不同，有这个if，1245没有这个if
                    ans = max(ans, maxLen + len);
                    maxLen = max(maxLen, len);
                }
            }
            return maxLen;
        };
        dfs(0); // dfs(0, -1)
        return ans + 1;
    }
};
// @lc code=end

