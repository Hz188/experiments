/*
 * @lc app=leetcode.cn id=2080 lang=cpp
 *
 * [2080] 区间内查询数字的频率
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class RangeFreqQuery {
private:
    unordered_map<int, vector<int>> pos{};
public:
    RangeFreqQuery(vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            pos[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        auto it = pos.find(value);
        if(it == pos.end()){
            return 0;
        }
        auto& index = it->second;
        return left_bound(index, right+1) - left_bound(index, left);
    }
private:
    int left_bound(vector<int>& nums, int target) {
        int l = -1, r = nums.size();
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

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
// @lc code=end

