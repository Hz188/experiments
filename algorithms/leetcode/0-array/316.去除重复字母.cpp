/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> freq{};
        unordered_set<char> in_ans{};
        for(char c: s) {
            freq[c]++;
        }
        int n = s.size();
        string ans{};
        for(int i = 0; i < n; i++) {
            char c = s[i];
            freq[c]--;
            if(in_ans.contains(c)) {
                continue;
            }
            while(!ans.empty() && c < ans.back() && freq[ans.back()]) {
                in_ans.erase(ans.back());
                ans.pop_back();
            }
            ans.push_back(c);
            in_ans.insert(c);
        }
        return ans;
    }
};
// https://leetcode.cn/problems/remove-duplicate-letters/solutions/2381483/gen-zhao-wo-guo-yi-bian-shi-li-2ni-jiu-m-zd6u/
// @lc code=end

