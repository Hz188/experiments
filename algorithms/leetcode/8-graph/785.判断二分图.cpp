/*
 * @lc app=leetcode.cn id=785 lang=cpp
 *
 * [785] 判断二分图
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    // 记录图是否符合二分图性质
    bool ok = true;
    // 记录图中节点的颜色，false 和 true 代表两种不同颜色
    vector<bool> color;
    // 记录图中节点是否被访问过
    vector<bool> visited;

public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        color = vector<bool>(n);
        visited = vector<bool>(n);
        // 因为图不一定是联通的，可能存在多个子图
        // 所以要把每个节点都作为起点进行一次遍历
        // 如果发现任何一个子图不是二分图，整幅图都不算二分图
        for(int v = 0; v < n; v++) {
            if(!visited[v]){
                dfs(graph, v);
            }
        }
        return ok;
    }

private:
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

