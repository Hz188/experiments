#include <vector>
#include <numeric>
#include <queue>
#include "并查集.cpp"

using namespace std;

vector<int> parent;

struct Edge{
    int from;
    int to;
    int weight;
    bool operator < (const Edge& e2) const {
        return weight < e2.weight;
    }
};

// Kruscal
int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        }); // 第一个相比第二个 true的话就是在你之前
        parent = vector<int>(n+1);
        iota(parent.begin() + 1, parent.end(), 1);
        int mst = 0;
        int count = n;
        for(auto& e : connections){
            int u = e[0];
            int v = e[1];
            int weight = e[2];
            if(connected(u, v)){
                continue;
            }
            mst += weight;
            m_union(u, v);
            count --;
        }
        return count == 1 ? mst : -1;
        
}

// Prim
class Prim {
private:
    // 核心数据结构，存储「横切边」的优先级队列
    // 三元组 {from, to, weight} 表示一条边
    priority_queue<vector<int> /*这里应该还要传一个比较器，按照weight的小根堆*/> pq;
    // 类似 visited 数组的作用，记录哪些节点已经成为最小生成树的一部分
    vector<bool> inMST;
    // 记录最小生成树的权重和
    int weightSum = 0;
    // graph 是用邻接表表示的一幅图，
    // graph[s] 记录节点 s 所有相邻的边
    vector<vector<vector<int> > > graph;

public:
    Prim(vector<vector<vector<int> > >& graph) {
        this->graph = graph;
        // 图中有 n 个节点
        int n = graph.size();
        this->inMST = vector<bool>(n);

        // 随便从一个点开始切分都可以，我们不妨从节点 0 开始
        inMST[0] = true;
        cut(0);
        // 不断进行切分，向最小生成树中添加边
        while(!pq.empty()) {
            vector<int> edge = pq.top();
            pq.pop();
            int to = edge[1];
            int weight = edge[2];
            if (inMST[to]) {
                // 节点 to 已经在最小生成树中，跳过
                // 否则这条边会产生环
                continue;
            }
            // 将边 edge 加入最小生成树
            weightSum += weight;
            inMST[to] = true;
            // 节点 to 加入后，进行新一轮切分，会产生更多横切边
            cut(to);
        }
    }

    // 将 s 的横切边加入优先队列
    void cut(int s) {
        // 遍历 s 的邻边
        for (vector<int>& edge : graph[s]) {
            int to = edge[1];
            if (inMST[to]) {
                // 相邻接点 to 已经在最小生成树中，跳过
                // 否则这条边会产生环
                continue;
            }
            // 加入横切边队列
            pq.push(edge);
        }
    }

    // 最小生成树的权重和
    int weightSum() {
        return weightSum;
    }

    // 判断最小生成树是否包含图中的所有节点
    bool allConnected() {
        for (bool connected : inMST) {
            if (!connected) {
                return false;
            }
        }
        return true;
    }
};

