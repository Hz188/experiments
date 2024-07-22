#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dijkstra(int n, vector<vector<pair<int, int>>>& graph, int start) {
        // 初始化距离数组，所有节点的初始距离为无穷大
        vector<int> distances(n, INT_MAX);
        distances[start] = 0; // 起点到起点的距离为0

        // 优先队列，存储（距离，节点）的对，按距离从小到大排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, start}); // 将起点加入优先队列

        while (!pq.empty()) {
            auto [currentDistance, u] = pq.top();
            pq.pop();

            // 如果当前距离大于已知的最短距离，则跳过
            if (currentDistance > distances[u]) {
                continue;
            }

            // 遍历与节点u相连的所有边
            for (auto& [v, weight] : graph[u]) {
                int distance = currentDistance + weight;
                // 如果找到更短的路径，则更新距离并将节点v加入优先队列
                if (distance < distances[v]) {
                    distances[v] = distance;
                    pq.push({distance, v});
                }
            }
        }

        return distances;
    }
};

int main() {
    int n = 5; // 节点数量
    vector<vector<pair<int, int>>> graph(n);
    
    // 添加边 (u, v, w) 表示从 u 到 v 有一条权重为 w 的边
    graph[0].push_back({1, 10});
    graph[0].push_back({4, 5});
    graph[1].push_back({2, 1});
    graph[1].push_back({4, 2});
    graph[2].push_back({3, 4});
    graph[3].push_back({2, 6});
    graph[3].push_back({0, 7});
    graph[4].push_back({1, 3});
    graph[4].push_back({2, 9});
    graph[4].push_back({3, 2});

    Solution sol;
    vector<int> distances = sol.dijkstra(n, graph, 0); // 从节点0开始

    // 输出结果
    for (int i = 0; i < distances.size(); ++i) {
        cout << "Distance from 0 to " << i << " is " << distances[i] << endl;
    }

    return 0;
}

/*
来用一个简单的故事来解释 Dijkstra 算法。

### 故事背景

想象一下，你是一个小朋友，住在一个有很多房子的小镇里。你想从你家（起点）出发，去拜访镇上每一栋房子（节点）。每条街道（边）都有不同的长度（权重），你想找到从你家到每一栋房子的最短路径。

### 角色介绍

-  **你**：小朋友，起点
-  **房子**：镇上的每一栋房子
-  **街道**：连接房子的道路，每条街道都有不同的长度

### 任务

你要找到从你家到每一栋房子的最短路径。

### 步骤

1. **标记起点**：你从家里出发，所以你家的距离是0。
2. **初始化地图**：把镇上的每一栋房子的距离都标记为一个很大的数字（表示还不知道怎么去）。
3. **选择最近的房子**：从你家出发，选择距离你最近的房子。
4. **更新距离**：看看从你家到这个房子的距离，再加上从这个房子到其他房子的距离，是否比你之前知道的距离更短。如果是，就更新距离。
5. **重复**：选择下一个最近的房子，重复上一步，直到你找到所有房子的最短路径。

### 具体步骤

1. **从家出发**：你家的距离是0。
2. **选择最近的房子**：比如说，你家到小明家有一条街道，长度是2，所以小明家的距离是2。
3. **更新其他房子的距离**：如果小明家到小红家的街道长度是3，那么你家到小红家的距离就是2（到小明家） + 3（小明家到小红家） = 5。
4. **继续选择最近的房子**：选择下一个距离最近的房子，重复上一步，直到你找到所有房子的最短路径。


### 总结

Dijkstra 算法就像你在小镇上找最短路径的过程，不断选择最近的房子，更新距离，直到找到所有房子的最短路径。希望这个故事能帮助你理解 Dijkstra 算法！

*/