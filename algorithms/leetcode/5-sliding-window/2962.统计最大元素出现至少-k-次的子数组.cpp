/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0;
        long long ans = 0;
        int max_num = *max_element(nums.begin(), nums.end());
        int cnt = 0;
        for(int right = 0; right < n; right ++) {
            int x = nums[right];
            if(x == max_num) cnt++;
            while(cnt >= k) {
                int y = nums[left];
                if(y == max_num) cnt--;
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end

