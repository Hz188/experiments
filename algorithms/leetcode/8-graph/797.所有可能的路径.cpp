/*
 * @lc app=leetcode.cn id=797 lang=cpp
 *
 * [797] 所有可能的路径
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    vector<vector<int>> res{};
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> path{};     // 维护递归过程中经过的路径
        traverse(graph, 0, path);
        return res;
    }
private:
    void traverse(vector<vector<int>>& graph, int s, vector<int>& path) {
        
        path.push_back(s);    // 添加节点 s 到路径

        int n = graph.size();
        if(s == n - 1) {
            res.push_back(path);        // 到达终点
            // 可以在这直接 return，但要 removeLast 正确维护 path
            // path.removeLast();
            // return;
            // 不 return 也可以，因为图中不包含环，不会出现无限递归
        }
        for(int v : graph[s]) { // 递归每个相邻节点
            traverse(graph, v, path);
        }
        path.pop_back();  // 从路径移出节点 s
    }
};
// @lc code=end

