/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    int findKthLargest(std::vector<int>& nums, int k) {
        // 小顶堆，堆顶是最小元素
        std::priority_queue<int, vector<int>, greater<>> pq;
        for (int e : nums) {
            // 每个元素都要过一遍二叉堆
            pq.push(e);
            // 堆中元素多于 k 个时，删除堆顶元素
            if (pq.size() > k) {
                pq.pop();
            }
        }
        // pq 中剩下的是 nums 中 k 个最大元素，
        // 堆顶是最小的那个，即第 k 个最大元素
        return pq.top();
    }
};
// @lc code=end

