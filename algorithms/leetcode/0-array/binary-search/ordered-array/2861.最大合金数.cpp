/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] 最大合金数
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxNumberOfAlloys(int n, int k, int budget, vector<vector<int>>& composition, vector<int>& stock, vector<int>& cost) {
        int mx = budget  + *min_element(stock.begin(), stock.end());
        int ans = 0;
        for (auto& comp: composition) {
            int left = ans;
            int right = mx + 1;
            while(left+1 < right) {
                long long mid = (right - left) / 2 + left;
                long long money = 0;
                // false (l mid)
                bool flag = true;
                for (int i = 0; i < n; i++) {
                    if (stock[i] < comp[i] * mid) {
                        money += (comp[i] * mid - stock[i]) * cost[i];
                        if (money > budget) {
                            flag = false;
                            break;
                        }
                    }
                }
                (flag ? left : right) = mid;
            }
            ans = left;
        }
        return ans;
    }

};
// @lc code=end

