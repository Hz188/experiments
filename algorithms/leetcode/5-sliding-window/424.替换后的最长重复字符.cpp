/*
 * @lc app=leetcode.cn id=424 lang=cpp
 *
 * [424] 替换后的最长重复字符
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> window{};
        int res = 0;
        int max_count = 0;
        for(int left = 0, right = 0; right < s.size(); right++){
            char c = s[right];
            window[c] ++;
            max_count = max(max_count, window[c]);

            int need_replace = right - left + 1 - max_count;
            if(need_replace > k) {
                char d = s[left];
                left++;
                window[d]--;
            }

            res = max(res, right - left + 1);
        }
        return res;
    }
};
// @lc code=end

