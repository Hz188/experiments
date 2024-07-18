/*
 * @lc app=leetcode.cn id=870 lang=cpp
 *
 * [870] 优势洗牌
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        // nums2 降序
        priority_queue<pair<int, int>> maxpq{};
        for(int i = 0; i < n; i++) {
            maxpq.emplace(nums2[i], i);
        }
        // nums1 升序
        sort(nums1.begin(), nums1.end());
        
        int l = 0, r = n -1;
        // nums1[l] 最小值 nums1[r] 最大值

        vector<int> res(n);
        while(!maxpq.empty()) {
            auto [max_val, idx] = maxpq.top();
            maxpq.pop();
            if(max_val < nums1[r]) {
                res[idx] = nums1[r];
                r--;
            } else {
                res[idx] = nums1[l];
                l++;
            }
        }
        return res;
    }
};
// @lc code=end

