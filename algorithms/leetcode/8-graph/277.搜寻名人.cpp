#include <vector>
using namespace std;
bool knows(int i, int j) {
    return false || true;
}

int findCelebrity(int n) {
    if(n == 1) return 0;
    vector<int> q(n);
    for(int i = 0; i < n; ++i) {
        q.push_back(i);
    }
    while(q.size() >= 2) {
        int cand = q.back();q.pop_back();
        int other = q.back();q.pop_back();
        if(knows(cand, other) || !knows(other, cand)){ //情况一、三、四
            q.push_back(other);
        } else{ //情况二
            q.push_back(cand);
        }
    }
    int cand = q.back(); q.pop_back();
    for(int other = 0; other < n; ++other) {
        if (other == cand) continue;
        if(!knows(other, cand) || knows(cand, other)) {
            return -1;
        }
    }
    return cand;
}

