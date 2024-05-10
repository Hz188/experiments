// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem1.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> valToIndex{};
        for(int i = 0; i < nums.size(); i++) {
            int need = target - nums[i];
            if(valToIndex.count(need)){
                return {valToIndex[need], i};
            }
            valToIndex[nums[i]] = i;
        }
        return {};
    }
};
// @lc code=end

