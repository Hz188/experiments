/*
 * @lc app=leetcode.cn id=315 lang=cpp
 *
 * [315] 计算右侧小于当前元素的个数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
    vector<int> res;
    vector<pair<int, int>> temp;
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        res = vector<int>(n);
        vector<pair<int, int>> num_index(n);
        temp = vector<pair<int,int>>(n);
        for(int i = 0; i < nums.size(); i++) {
            num_index[i] = make_pair(nums[i], i);
        }
        sort(num_index, 0, num_index.size() -1);
        return res;
    }

    void sort(vector<pair<int, int>>& nums, int l, int r) {
        if(l == r) return;
        int mid = (r - l) / 2 + l;
        sort(nums, l, mid);
        sort(nums, mid+1, r);
        merge(nums, l, mid, r);
    }

    void merge(vector<pair<int, int>>& nums, int l, int mid, int r) {

        for(int i = l; i <= r; i++){
            temp[i] = nums[i];
        }

        int i = l, j = mid+1;
        for(int p = l; p <= r; p++) {
            if (i == mid + 1) {
                // 左半边数组已全部被合并
                nums[p] = temp[j++];
            } else if (j == r + 1) {
                // 右半边数组已全部被合并
                nums[p] = temp[i++];
                res[nums[p].second] += j - mid - 1;
            } else if (temp[i] > temp[j]) {
                nums[p] = temp[j++];
            } else { // temp[i] <= temp[j]
                nums[p] = temp[i++];
                res[nums[p].second] += j - mid - 1;
            }
        }
    }
};
// @lc code=end