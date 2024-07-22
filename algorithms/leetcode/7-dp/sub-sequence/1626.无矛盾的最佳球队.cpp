/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */

// @lc code=start
#include <vector>
#include <map>
#include <utility>
using namespace std;
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pair<int, int>> arr {};
        int n = ages.size();
        for(int i = 0; i < n; i++) {
            arr.push_back({ages[i], scores[i]});
        }
        sort(arr.begin(), arr.end());
        vector<int> f(n);
        for(int i = 0; i < n; i++) {
            f[i] = arr[i].second;
            for(int j = 0; j < i; j++) {
                if(arr[i].second >= arr[j].second) {
                    f[i] = max(f[j] + arr[i].second, f[i]);
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end

