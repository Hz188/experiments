#include <vector>
using namespace std;
class Solution {
public:
    int jewelleryValue(vector<vector<int>>& frame) {
        int m = frame.size();
        int n = frame[0].size();
        if(m == 1 && n == 1 && frame[0][0] == 0) return 0;

        vector<vector<int>> f(m, vector<int>(n, 0));
        f[0][0] = frame[0][0];
        for(int i = 1; i < n; i++) {
            f[0][i] = f[0][i-1] +frame[0][i];
        }
        for(int i = 1; i < m; i++) {
            f[i][0] = f[i-1][0] + frame[i][0];
        }

        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                f[i][j] = max(f[i-1][j], f[i][j-1]) + frame[i][j];
            }
        }
        return f[m-1][n-1];
    }
};