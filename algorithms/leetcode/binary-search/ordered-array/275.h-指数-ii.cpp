/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = n;
        int ans;
        while(l < r) {
            int mid = (r - l) / 2 + l;
            int cite = citations[mid];
            int num = n - mid; // >= cite 有 num篇
            //false: 以当前论文的引用为基准，往后计算，无法满足h指数定义
            //true: 从当前论文的引用数为基准，往后计算，能够满足h指数定义
            if(num > cite) { // 不满足h指数定义：num篇论文引用至少num次
                l = mid+1; // false [0...l-1] 红色都不满足
            } else if (num <= cite) { //满足h指数定义
                r = mid; // true [r...] 蓝色都满足
            }
        }
        // l == r
        return n - l;
    }
};
// @lc code=end

