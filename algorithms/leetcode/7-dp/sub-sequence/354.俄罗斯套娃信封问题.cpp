/*
 * @lc app=leetcode.cn id=354 lang=cpp
 *
 * [354] 俄罗斯套娃信封问题
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();

        sort(envelopes.begin(), envelopes.end(), [](const auto& a, const auto& b){
            return a[0] == b[0] ? b[1] < a[1] : a[0] < b[0];
            // 按宽度升序，再按高度降序
        });
        // 超时
        // vector<int> f(n, 1);
        // for(int i = 0; i < n; i++) {
        //     for(int j = 0; j < i; j++) {
        //         if(envelopes[i][1] > envelopes[j][1]) {
        //             f[i] = max(f[j] + 1, f[i]);
        //         }
        //     }
        // }

        // bs
        vector<int> g;
        for(auto& e: envelopes) {
            auto it = lower_bound(g.begin(), g.end(), e[1]);
            if(it == g.end()) {
                g.push_back(e[1]);
            } else {
                *it = e[1];
            }
        }
        return g.size();
    }
};
// @lc code=end

