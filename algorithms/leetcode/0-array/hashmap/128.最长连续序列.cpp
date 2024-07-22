/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 */

// @lc code=start
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set(nums.begin(), nums.end());
        int res = 0;

        for(int num: set) {
            if(set.find(num - 1) != set.end()) {
                continue; //找到一个数是一个连续序列的开头
            }

            int cur_num = num;
            int cur_len = 1;
            while(set.find(cur_num + 1) != set.end()) {
                cur_num ++;
                cur_len ++;
            }
            res = max(res, cur_len);
        }
        return res;


    }
};
// @lc code=end

