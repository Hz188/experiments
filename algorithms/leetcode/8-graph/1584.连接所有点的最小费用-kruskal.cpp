/*
 * @lc app=leetcode.cn id=1584 lang=cpp
 *
 * [1584] 连接所有点的最小费用
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution {
    vector<int> parent;     // 存储每个节点的父节点
    int count;
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<Edge> edges;
        for(int i{0}; i < n; i++) {
            for(int j{i+1}; j < n; j++) {
                int distance = dist(points[i], points[j]);
                edges.push_back({i, j, distance});
            }
        }
        sort(edges.begin(), edges.end());
        count = n;
        parent = vector<int>(n);
        iota(parent.begin(), parent.end(), 0);
        int weight{0};
        for(auto& e : edges){
            int u = e.from;
            int v = e.to;
            int w = e.weight;
            if(connected(u, v)){
                continue;
            }
            m_union(e.to, e.from);
            weight += w;            
        }
        return weight;
    }
private:
    struct Edge{
        int from;
        int to;
        int weight;
        bool operator < (const Edge& e2) const {
		    return weight < e2.weight;
        }
	};
    
    int dist(vector<int>& p1, vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }

    // 将节点 p 和节点 q 连通
    void m_union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        
        if (rootP == rootQ)
            return;
        
        parent[rootQ] = rootP;
        // 两个连通分量合并成一个连通分量
        count--;
    }

    // 判断节点 p 和节点 q 是否连通
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP == rootQ;
    }

    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
};
// @lc code=end

