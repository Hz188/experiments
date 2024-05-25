/*
 * @lc app=leetcode.cn id=2730 lang=cpp
 *
 * [2730] 找到最长的半重复子字符串
 */

// @lc code=start
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.size();
        int left = 0;
        int duplicate_count = 0;
        int ans = 1;
        for(int right = 1; right < n; right++){
            if(s[right] == s[right-1]) duplicate_count++;
            while(duplicate_count > 1){
                if(left < right && s[left] == s[left+1])
                    duplicate_count--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end

