/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<bool> inMST(n, false); // 用于标记节点是否已包含在最小生成树中
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;

        minHeap.push({0, 0}); // 从节点0开始
        int result = 0;
        int edgesUsed = 0;

        while (edgesUsed < n) {
            auto [weight, u] = minHeap.top();
            minHeap.pop();

            if (inMST[u]) {
                continue;
            }

            inMST[u] = true;
            result += weight;
            edgesUsed++;

            for (int v = 0; v < n; ++v) {
                if (!inMST[v]) {
                    int distance = abs(points[u][0] - points[v][0]) + abs(points[u][1] - points[v][1]);
                    minHeap.push({distance, v});
                }
            }
        }

        return result;
    }
};

// @lc code=end

