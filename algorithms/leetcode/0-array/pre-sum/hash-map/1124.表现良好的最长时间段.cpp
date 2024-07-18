/*
 * @lc app=leetcode.cn id=1124 lang=cpp
 *
 * [1124] 表现良好的最长时间段
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestWPI(vector<int>& hours) {
        int n = hours.size();
        vector<int> pre_sum(n + 1);
        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + (hours[i] > 8 ? 1: -1);
        }
        
        unordered_map<int, int> val_to_index;
        for(int i = 0; i < n+1; i++) {
            if(!val_to_index.contains(pre_sum[i])) {
                val_to_index[pre_sum[i]] = i;
            }
        }
        int res = 0;
        for(int i = 0; i < n+1; i++) {
            if(pre_sum[i] > 0) {
                res = max(res, i);
            } else {
                if(val_to_index.contains(pre_sum[i] - 1)){
                    int j = val_to_index[pre_sum[i] - 1];
                    res = max(res, i-j);
                }
            }
        }
        return res;
    }
};
// @lc code=end

