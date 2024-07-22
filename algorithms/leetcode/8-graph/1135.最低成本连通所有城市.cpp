class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(), connections.end(), [](auto& a, auto& b){
            return a[2] < b[2];
        });
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
private:
    vector<int> parent;
    void m_union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if(rootP == rootQ){
            return;
        }
        parent[rootQ] = rootP;
    }
    int find(int x) {
        if(parent[x] != x){
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    bool connected(int p, int q) {
        return find(p) == find(q);
    }
};