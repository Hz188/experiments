/*
 * @lc app=leetcode.cn id=493 lang=cpp
 *
 * [493] 翻转对
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    vector<int> temp{};
    int ans = 0;
public:
    int reversePairs(vector<int>& nums) {
        temp = vector<int>(nums.size());
        sort(nums, 0, nums.size() - 1);
        return ans;
    }
    void sort(vector<int>& nums, int l, int r) {
        if(l == r) return;
        int mid = (r - l) / 2 + l;
        sort(nums, l, mid);
        sort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<int>& nums, int l, int mid, int r) {

        for(int i = l; i <= r; i++){
            temp[i] = nums[i];
        }

    // 进行效率优化，维护左闭右开区间 [mid+1, end) 中的元素乘 2 小于 nums[i]
        // 为什么 end 是开区间？因为这样的话可以保证初始区间 [mid+1, mid+1) 是一个空区间
        int end = mid + 1;
        for (int i = l; i <= mid; i++) {
            // nums 中的元素可能较大，乘 2 可能溢出，所以转化成 long
            while (end <= r && (long)nums[i] > (long)nums[end] * 2) {
                end++;
            }
            ans += end - (mid + 1);
        }

        int i = l, j = mid+1;
        for(int p = l; p <= r; p++) {
            if (i == mid + 1) {
                // 左半边数组已全部被合并
                nums[p] = temp[j++];
            } else if (j == r + 1) {
                // 右半边数组已全部被合并
                nums[p] = temp[i++];
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else { // temp[i] <= temp[j]
                nums[p] = temp[i++];
            }
        }
    }
};
// @lc code=end

