/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int idx =  lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int i = idx - 1;
        int j = idx;
        vector<int> res(nums.size());
        int k = 0;
        while(i >= 0 && j < nums.size()) {
            int i_square = nums[i] * nums[i];
            int j_suqare = nums[j] * nums[j];
            if(i_square < j_suqare) {
                res[k] = i_square;
                i--;
            } else {
                res[k] = j_suqare;
                j++;
            }
            k++;
        }
        while(j < nums.size()) {
            res[k++] = nums[j] * nums[j];
            j++;
        }
        while(i >= 0) {
            res[k++] = nums[i] * nums[i];
            i--;
        }
        return res;
    }

    // 题解标准解法：两边靠中间
    vector<int> sortedSquares_2(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = n - 1;
        int p = n - 1;
        vector<int> res(n);
        while (i <= j) {
            if (abs(nums[i]) > abs(nums[j])) {
                res[p] = nums[i] * nums[i];
                i++;
            } else {
                res[p] = nums[j] * nums[j];
                j--;
            }
            p--;
        }
        return res;
    }
};
// @lc code=end

