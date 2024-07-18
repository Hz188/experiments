/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums2.size();
        vector<int> res(n, -1);
        stack<int> s;
        unordered_map<int, int> val_to_index{};
        for(int i = 0; i < n; i++) {
            while(!s.empty() && nums2[i] > nums2[s.top()]) {
                int j = s.top();
                res[j] = nums2[i];
                s.pop();
            }
            val_to_index[nums2[i]] = i;
            s.push(i);
        }
        vector<int> ret(nums1.size(), -1);
        for(int i = 0; i < nums1.size(); i++) {
            ret[i] = res[val_to_index[nums1[i]]];
        }
        return ret;
    }
};
// @lc code=end

