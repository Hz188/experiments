/*
 * @lc app=leetcode.cn id=673 lang=cpp
 *
 * [673] 最长递增子序列的个数
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), max_len = 0, ans = 0;
        vector<int> f(n, 1), cnt(n);
        for(int i = 0; i < n; i++) {
            f[i] = 1;
            cnt[i] = 1;
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j]){
                    if(f[j]+1 > f[i]) {
                        f[i] = f[j]+1;
                        cnt[i] = cnt[j];
                    } else if(f[j]+1 == f[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }
            max_len = max(max_len, f[i]);
        }
        for(int i = 0; i < n; i++) {
            if(f[i] == max_len) ans += cnt[i];
        }
        return ans;
    }
};
// @lc code=end

