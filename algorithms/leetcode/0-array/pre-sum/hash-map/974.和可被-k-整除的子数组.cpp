/*
 * @lc app=leetcode.cn id=974 lang=cpp
 *
 * [974] 和可被 K 整除的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre_sum(n + 1);
        for (int i = 0; i < n; i++) {
            pre_sum[i + 1] = pre_sum[i] + nums[i];
        }
        
        unordered_map<int, int> count;
        count[0] = 1;
        int res = 0;
        for(int i = 0; i < n; i++) {
            int remainder = pre_sum[i+1] % k;
            if(remainder < 0) {
                remainder += k;
            }
            if(count.contains(remainder)){
                res += count[remainder];
            } 
            count[remainder]++; 
        }
        return res;
    }
    
};
// @lc code=end

