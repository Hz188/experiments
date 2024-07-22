/*
 * @lc app=leetcode.cn id=210 lang=cpp
 *
 * [210] 课程表 II
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    // 主函数
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // 建图，和环检测算法相同
        vector<vector<int>> graph = buildGraph(numCourses, prerequisites);
        // 计算入度，和环检测算法相同
        vector<int> indegree(numCourses, 0);
        for (const auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            indegree[to]++;
        }

        // 根据入度初始化队列中的节点，和环检测算法相同
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 记录拓扑排序结果
        vector<int> res(numCourses);
        // 记录遍历节点的顺序（索引）
        int count = 0;
        // 开始执行 BFS 算法
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            // 弹出节点的顺序即为拓扑排序结果
            res[count] = cur;
            count++;
            for (int next : graph[cur]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        if (count != numCourses) {
            // 存在环，拓扑排序不存在
            return {};
        }
        
        return res;
    }

    // 建图函数
    vector<vector<int>> buildGraph(int numCourses, vector<vector<int>>& prerequisites) {
        // 图中共有 numCourses 个节点
        vector<vector<int>> graph(numCourses);
        for (const auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            // 修完课程 from 才能修课程 to
            // 在图中添加一条从 from 指向 to 的有向边
            graph[from].push_back(to);
        }
        return graph;
    }
};
// @lc code=end

