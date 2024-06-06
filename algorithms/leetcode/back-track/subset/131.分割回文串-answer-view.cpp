/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @lc code=start
#include <vector>
#include <string>
#include <deque>
using namespace std;
class Solution {
public:

    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        dfs(s, 0);
        return res;
    }

    //答案视角
    void dfs(string &s, int i) {
        if (i == s.length()) {
            res.push_back(path);
        }
        for (int j = i; j < s.length(); j++) {
            if (isPalindrome(s, i, j)) {
                path.push_back(s.substr(i, j - i + 1));
                dfs(s, j + 1);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(string &s, int lo, int hi) {
        while (lo < hi) {
            if (s[lo] != s[hi]) {
                return false;
            }
            lo++;
            hi--;
        }
        return true;
    }
};
// @lc code=end

