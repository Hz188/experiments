/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
#include <queue>
#include <vector>
#include <tuple>
using namespace std;
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix[0].size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> pq;

        // 初始化优先级队列，把每一行的第一个元素装进去
        for (int i = 0; i < matrix.size(); i++) {
            pq.push({matrix[i][0], i, 0});
        }

        int res = -1;
        // 执行合并多个有序链表的逻辑，找到第 k 小的元素
        while (k > 0) {
            auto [val, i, j] = pq.top();
            pq.pop();
            res = val;
            k--;
            // 链表中的下一个节点加入优先级队列
            if (j + 1 < n) {
                pq.push({matrix[i][j + 1], i, j + 1});
            }
        }
        return res;
    }
};
// @lc code=end

