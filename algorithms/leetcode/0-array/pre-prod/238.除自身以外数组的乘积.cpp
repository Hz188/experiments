/*
 * @lc app=leetcode.cn id=238 lang=cpp
 *
 * [238] 除自身以外数组的乘积
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_prod(n+1, 1);  // pre[i] = [0...i)
        vector<int> suf_prod(n+1, 1);  // suf[i] = [i...n-1]
        for(int i = 0; i < n; i++) {
            pre_prod[i+1] = pre_prod[i] * nums[i];
        }
        for(int i = n-1; i >= 0; i--) {
            suf_prod[i] =  suf_prod[i+1] * nums[i];
        }
        vector<int> res(n);
        // res[0] = suf_prod[1];
        // res[n-1] = pre_prod[n-1];
        for(int i = 0; i < n; i++) {
            res[i] = suf_prod[i+1] * pre_prod[i];
        }
        return res;
    }
};
// @lc code=end

