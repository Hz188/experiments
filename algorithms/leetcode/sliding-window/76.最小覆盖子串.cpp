// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem76.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        unordered_map<char, int> need{};
        unordered_map<char, int> now{};
        for(char c: t) need[c]++;
        int ans_left = -1;
        int ans_right = n;
        int valid = 0;
        for(int left = 0, right = 0; right < n; right++) {
            char c = s[right];
            now[c]++;
            if(need.count(c) && now[c] == need[c]) valid++;
            while(valid == need.size()){ 
                if(right - left < ans_right - ans_left){
                    ans_right = right;
                    ans_left = left;
                }
                char d = s[left];
                left++;
                if(need.count(d) && now[d] == need[d]) {
                    valid--;
                }
                now[d]--;
            }
        }
        return ans_left < 0 ? "" : s.substr(ans_left, ans_right - ans_left + 1);

    }
};
// @lc code=end

