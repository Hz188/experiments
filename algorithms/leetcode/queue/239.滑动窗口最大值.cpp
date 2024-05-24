/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans{};
        int n = nums.size();
        deque<int>  q{};
        for(int i = 0; i < n; i++) {
            // 1. into window
            while(!q.empty() && nums[q.back()] <= nums[i]) {
                q.pop_back();
            }
            q.push_back(i);
            // 2. out of window
            if(i - q.front() + 1 > k) { 
                // count the number of element in window
                // window size = i - q.front() + 1
                // if size > k, should pop the queue front element
                q.pop_front();
            }
            // 3. record answer
            if(i >= k-1){
                ans.push_back(nums[q.front()]);
            }
        }
        return ans;
    }
};
// @lc code=end

