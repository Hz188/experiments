#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> diff(length, 0);
        for(auto& u : updates) {
            int l =  u[0];
            int r = u[1];
            int val = u[2];
            diff[l] += val;
            if(r+1 < length){
                diff[r+1] -= val;
            }
        }
        vector<int> res(length, 0);
        res[0] = diff[0];
        for(int i = 1; i < length; i++) {
            res[i] = res[i-1] + diff[i];
        }
        return res;
    }
};