/*
 * @lc app=leetcode.cn id=4 lang=cpp
 *
 * [4] 寻找两个正序数组的中位数
 */

// @lc code=start
#include <queue>
using namespace std;
class Solution {
private:
    priority_queue<int, std::vector<int>, std::greater<>> large;
    priority_queue<int, std::vector<int>, std::less<>> small;
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0; i < nums1.size(); i++) {
            addNum(nums1[i]);
        }
        for(int i = 0; i < nums2.size(); i++) {
            addNum(nums2[i]);
        }
        if (large.size() < small.size()) {
            return small.top();
        } else if (large.size() > small.size()) {
            return large.top();
        }
        // 如果元素一样多，两个堆堆顶元素的平均数是中位数
        return (double)(large.top() + small.top()) / 2.0;
    }
    void addNum(int num) {
        if (small.size() >= large.size()) {
            small.push(num);
            large.push(small.top());
            small.pop();
        } else {
            large.push(num);
            small.push(large.top());
            large.pop();
        }
    }
};
// @lc code=end

