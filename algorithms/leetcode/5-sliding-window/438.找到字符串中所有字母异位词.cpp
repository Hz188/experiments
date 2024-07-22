/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        unordered_map<char, int> need {};
        unordered_map<char, int> window {};
        vector<int> res {};
        for(char c: p) {
            need[c]++;
        }
        int valid = need.size();
        int n = s.size();
        for(int left = 0, right = 0; right < n; right++) {
            char c = s[right];
            window[c]++;
            if(window[c] == need[c]) valid --;
            while(right - left + 1 > p.size()) {
                char d = s[left++];
                if(window[d] == need[d]) valid ++;
                window[d]--;
            }
            if(valid == 0) res.push_back(left);
        }
        return res;
    }
};
// @lc code=end

