#include <vector>
using namespace std;

// 记录被遍历过的节点
vector<bool> visited;
// 记录从起点到当前节点的路径
vector<bool> onPath;

class Graph {

};
/* 图遍历框架 */
void traverse(vector<vector<int>> graph, int s) {
    if (visited[s]) return;
    // 经过节点 s，标记为已遍历
    visited[s] = true;
    // 做选择：标记节点 s 在路径上
    onPath[s] = true;
    for (int neighbor : graph[s]) {
        traverse(graph, neighbor);
    }
    // 撤销选择：节点 s 离开路径
    onPath[s] = false;
}