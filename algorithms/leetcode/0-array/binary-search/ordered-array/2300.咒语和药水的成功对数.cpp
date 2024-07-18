/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        // sort(spells.begin(), spells.end());
        sort(potions.begin(), potions.end());
        int n_spell = spells.size();
        int n_potion = potions.size();
        vector<int> ans{};
        for(int i = 0; i < n_spell; ++i) {
            long long bound_potion = success / (long)spells[i];
            if(success % spells[i] != 0)
                bound_potion++;
            int n = left_bound(potions, bound_potion);
            ans.push_back(n_potion - n);
        }
        return ans;
    }
    int left_bound(vector<int>& nums, long long target) {
        int n = nums.size();
        int l = -1, r = n;
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
// @lc code=end

