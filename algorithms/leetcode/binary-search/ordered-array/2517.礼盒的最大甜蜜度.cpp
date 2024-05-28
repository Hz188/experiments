/*
 * @lc app=leetcode.cn id=2517 lang=cpp
 *
 * [2517] 礼盒的最大甜蜜度
 */

// @lc code=start
#include <vector>
#include <functional>
#include <algorithm>
#include <ranges>
using namespace std;
class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        sort(price.begin(), price.end());
        int n = price.size();
        int max = (ranges::max(price) - ranges::min(price))/ (k-1); 
        auto f = [&](int d) -> int {
            int cnt = 1, pre = price[0];
            for (int p: price) {
                if (p >= pre + d) {
                    cnt++;
                    pre = p;
                }
            }
            return cnt;
        };

        int left = 0, right = (price.back() - price[0]) / (k - 1) + 1;
        while (left + 1 < right) { // 开区间不为空
            // 循环不变量：
            // f(left) >= k
            // f(right) < k
            int mid = left + (right - left) / 2;
            (f(mid) >= k ? left : right) = mid;
        }
        return left;
    }
};
// @lc code=end