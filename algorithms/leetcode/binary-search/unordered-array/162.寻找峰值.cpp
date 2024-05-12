/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        bool open_interval = true;
        return open_interval ? findPeakOpen(nums): findPeakClose(nums);
    }
private:
    //闭区间
    int findPeakClose(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n-2;
        while(left <= right) {
            int mid = (right - left) / 2 + left;
            int x = nums[mid];
            int y = nums[mid+1];
            //[left, mid] [mid+1, right]
            if(x < y) {
                // mid 在峰顶左侧，[...mid]为红色
                left = mid+1;
            } else { // x >= y, 题目条件中说了，相邻元素不存在相等
                // mid 在峰顶右侧或峰顶，[mid...]为蓝色
                right = mid-1;
            }
        }
        //最终答案是蓝色的第一个元素，也就是left
        return left;
    }
    //开区间形式
    int findPeakOpen(vector<int>& nums) {
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left < right) {
            int mid = (right - left) / 2 + left;
            int x = nums[mid];
            int y = nums[mid+1];
            //[left, mid, mid+1, right)
            if(x < y) { // x < y, x红色
                left = mid+1;
            } else { //x > y , x蓝色
                right = mid;
            }
        }
        return left;
    }
};
// @lc code=end

