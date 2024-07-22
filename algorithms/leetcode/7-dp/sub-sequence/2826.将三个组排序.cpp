/*
 * @lc app=leetcode.cn id=2826 lang=cpp
 *
 * [2826] 将三个组排序
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> f(n, 1);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < i; j++) {
                if(nums[i] >= nums[j]) {
                    f[i] = max(f[j] + 1, f[i]);
                }
            }
        }

        int lis = *max_element(f.begin(), f.end());
        return n - lis;
    }
};
// @lc code=end

