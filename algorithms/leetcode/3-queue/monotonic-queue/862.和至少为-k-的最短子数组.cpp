/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
#include <vector>
#include <deque>
#include <climits>
using namespace std;
class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), ans = n + 1;
        long s[n + 1];
        s[0] = 0L;
        for (int i = 0; i < n; ++i)
            s[i + 1] = s[i] + nums[i]; // 计算前缀和
        deque<int> q;
        for (int i = 0; i <= n; ++i) {
            while (!q.empty() && s[i] - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front(); // 优化一
            }
            while (!q.empty() && s[q.back()] >= s[i])
                q.pop_back(); // 优化二
            q.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};
// @lc code=end

