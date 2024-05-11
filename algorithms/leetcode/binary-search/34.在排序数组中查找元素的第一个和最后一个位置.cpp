// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem34.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1, -1};
        }
        return {left_bound(nums, target), right_bound(nums, target)};
        //技巧：可以转换为 left_bound(target), left_bound(target+1)这样的问题，只用写一个函数
    }
private:
    int left_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] < target) {
                left = mid + 1;
            } else{
                right = mid;
            }
        }
        if(left == n || nums[left] != target) left = -1;
        return left;
    }
    int right_bound(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n;
        while(left < right) {
            int mid = (right - left) / 2 + left;
            if(nums[mid] > target) {
                right = mid;
            } else{
                left = mid + 1;
            }
        }
        if (left == 0 || nums[left-1] != target) return  -1;
        return left - 1;
    }
};
// @lc code=end

