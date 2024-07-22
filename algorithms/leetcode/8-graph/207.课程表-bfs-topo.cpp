/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto graph = buildGraph(numCourses, prerequisites);

        auto indegree = vector<int>(numCourses, 0);
        for (const auto& edge : prerequisites) {
            int from = edge[1], to = edge[0];
            indegree[to]++;
        }

        queue<int> q;
        for(int i = 0; i < numCourses; i++) {
            if(indegree[i] == 0) {
                q.push(i);
            }
        }
        int count = 0;
        while(!q.empty()){
            int cur = q.front();
            q.pop();
            count++;
            for(int v: graph[cur]) {
                indegree[v]--;
                if(indegree[v] == 0) {
                    q.push(v);
                }
            }
        }
        if(count != numCourses) {
            return false;
        }
        return true;
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

