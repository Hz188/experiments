/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
private:
    int _lower, _upper;
    vector<long> temp{};
    int count = 0;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        _lower = lower;
        _upper = upper;
        vector<long> pre_sum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) {
            pre_sum[i+1] = pre_sum[i] + nums[i];
        }
        temp = vector<long>(nums.size() + 1);
        sort(pre_sum, 0, pre_sum.size() - 1);
        return count;
    }

    void sort(vector<long>& nums, int l, int r) {
        if(l == r) return;
        int mid = (r - l) / 2 + l;
        sort(nums, l, mid);
        sort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<long>& nums, int l, int mid, int r) {

        for(int i = l; i <= r; i++){
            temp[i] = nums[i];
        }
        // 进行效率优化
        // 维护左闭右开区间 [start, end) 中的元素和 nums[i] 的差在 [lower, upper] 中
        int start = mid + 1, end = mid + 1;
        for (int i = l; i <= mid; i++) {
            // 如果 nums[i] 对应的区间是 [start, end)，
            // 那么 nums[i+1] 对应的区间一定会整体右移，类似滑动窗口
            while (start <= r && nums[start] - nums[i] < _lower) {  
                start++;
            }
            // start -> nums[start] - nums[i] >= _lower
            while (end <= r && nums[end] - nums[i] <= _upper) {
                end++;
            }
            // end -> nums[end] - nums[i] > _upper
            // [start, end) -> 满足条件
            count += end - start;
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
            } else {
                nums[p] = temp[i++];
            }
        }
    }
};
// @lc code=end

