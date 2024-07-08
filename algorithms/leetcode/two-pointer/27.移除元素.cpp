/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0; // [0..k) remove的元素
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
// @lc code=end

