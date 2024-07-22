/*
 * @lc app=leetcode.cn id=740 lang=cpp
 *
 * [740] 删除并获得点数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    int rob(vector<int>& nums) {
        int size = nums.size();

        int f0 = nums[0], f1 = max(nums[0], nums[1]);
        for(int i = 2; i < size; i++) {
            int f2 = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = f2;
        }
        return f1;
    }
public:
    int deleteAndEarn(vector<int>& nums) {
        int max_val = 0;
        for(int v: nums) {
            max_val = max(v, max_val);
        }
        vector<int> sum(max_val+1);
        for(int val: nums) {
            sum[val] += val;
        }

        return rob(sum);
    }
};
// @lc code=end

