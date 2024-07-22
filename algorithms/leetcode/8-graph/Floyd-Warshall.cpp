#include <iostream>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> floydWarshall(int n, vector<vector<int>>& graph) {
        // 初始化距离矩阵
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));

        // 将图中的边权重初始化到距离矩阵中
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i == j) {
                    dist[i][j] = 0; // 自己到自己的距离是0
                } else if (graph[i][j] != -1) {
                    dist[i][j] = graph[i][j]; // 有边的地方设置为边的权重
                }
            }
        }

        // Floyd-Warshall算法
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX) {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }

        return dist;
    }
};

int main() {
    int n = 4; // 节点数量
    vector<vector<int>> graph = {
        {0, 3, -1, 7},
        {8, 0, 2, -1},
        {5, -1, 0, 1},
        {2, -1, -1, 0}
    };

    Solution sol;
    vector<vector<int>> shortestPaths = sol.floydWarshall(n, graph);

    // 输出结果
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (shortestPaths[i][j] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << shortestPaths[i][j] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
