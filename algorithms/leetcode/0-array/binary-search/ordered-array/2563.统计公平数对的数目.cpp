/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 *
 * [2563] 统计公平数对的数目
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long ans = 0;
        for(int i = 0; i < n; i++) {
            int x = nums[i]; // need [lower-x, upper-x]
            int min = lower - x;
            int max = upper - x;
            int l = left_bound(nums, min, i+1);
            int r = left_bound(nums, max+1, i+1);
            ans += r - l;
        }
        return ans;
    }
private:
    int left_bound(vector<int>& nums, int target, int start) {
        int n = nums.size();
        int l = start-1, r = n;
        while(l + 1 < r) { 
            int mid = (r - l) / 2 + l;
            if(nums[mid] < target) {
                l = mid;
            } else {
                r = mid;
            }
        }
        return r;
    }
};
// @lc code=end

