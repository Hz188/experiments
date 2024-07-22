/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @lc code=start
#include <vector>
#include <functional>
#include <stack>
using namespace std;
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        auto graph = buildGraph(numCourses, prerequisites);
        vector<int> visited(numCourses, 0);
        bool has_cycle = false;
        stack<int> st;
        function<void(int)> dfs = [&] (int s) {
            visited[s] = 1;
            for(int v: graph[s]) {
                if(visited[v] == 0) {
                    dfs(v);
                } else if(visited[v] == 1) {
                    has_cycle = true;
                    return;
                }
            }
            visited[s] = 2;
            st.push(s);
        };
        for(int i = 0; i < numCourses; i++) {
            if(visited[i]) continue;
            dfs(i);
        }

        return !has_cycle;
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

