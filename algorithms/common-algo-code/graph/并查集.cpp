#include <vector>
using namespace std;

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