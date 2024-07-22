/*
 * @lc app=leetcode.cn id=567 lang=cpp
 *
 * [567] 字符串的排列
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> need{};
        unordered_map<char, int> window{};
        for(char c: s1) {
            need[c]++;
        }
        int valid = need.size();
        for(int left = 0, right = 0; right < s2.size(); right++) {
            char c = s2[right];
            window[c]++;
            if(window[c] == need[c]) valid--;
            if(right - left + 1 > s1.size()) {
                char d = s2[left++];
                if(window[d] == need[d]) valid++;
                window[d]--;
            }
            if(valid == 0) return true;
        }
        return false;
    }
};
// @lc code=end

