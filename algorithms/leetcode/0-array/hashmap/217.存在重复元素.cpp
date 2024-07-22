/*
 * @lc app=leetcode.cn id=217 lang=cpp
 *
 * [217] 存在重复元素
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> freq{};
        for(int x : nums) {
            freq[x]++;
            if(freq[x] > 1) return true;
        }
        return false;
    }
};
// @lc code=end

