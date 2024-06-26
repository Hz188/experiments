/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> window{};
        int ans = 0;
        int left = 0, right = 0;
        int n = s.size();
        while (right < n) {
            char c = s[right];
            right++;
            window[c]++;
            while(window[c] > 1){
                char d = s[left];
                left++;
                window[d]--;
            }
            ans = max(ans, right - left);
        }
        return ans;
    }
};
// @lc code=end

