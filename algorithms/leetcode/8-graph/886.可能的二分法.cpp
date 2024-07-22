/*
 * @lc app=leetcode.cn id=886 lang=cpp
 *
 * [886] 可能的二分法
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> graph(n+1);
        for(auto& dis: dislikes) {
            graph[dis[0]].push_back(dis[1]);
            graph[dis[1]].push_back(dis[0]);
        }
        visited.resize(n+1, false);
        color.resize(n+1, false);
        for(int i = 1; i <= n; i++) {
            if(!visited[i]) {
                dfs(graph, i);
            }
        }
        return ok;
    }
private:
    bool ok = true;
    vector<bool> visited;
    vector<bool> color;
    void dfs(vector<vector<int>>& graph, int v){
        if(!ok)  // 如果已经确定不是二分图了，就不用浪费时间再递归遍历了
            return;
        
        visited[v] = true;
        for(auto& adj : graph[v]) {
            if(!visited[adj]){
                // 相邻节点 w 没有被访问过
                // 那么应该给节点 w 涂上和节点 v 不同的颜色
                color[adj] = !color[v];
                dfs(graph, adj);
            } else {
                // 相邻节点 w 已经被访问过
                // 根据 v 和 w 的颜色判断是否是二分图
                if(color[v] == color[adj]){
                    ok = false;
                    return;
                }
            }
        }
    }
};
// @lc code=end

