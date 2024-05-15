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
        backtrack(s, 0);
        return res;
    }

    //答案视角
    void backtrack(string &s, int start) {
        if (start == s.length()) {
            res.push_back(path);
        }
        for (int i = start; i < s.length(); i++) {
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                backtrack(s, i + 1);
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
    //输入视角
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();

        // start 表示当前这段回文子串的开始位置
        function<void(int, int)> dfs = [&](int i, int start) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }

            // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
            if (i < n - 1)
                dfs(i + 1, start);

            // 选 i 和 i+1 之间的逗号（把 s[i] 作为子串的最后一个字符）
            if (isPalindrome(s, start, i)) {
                path.push_back(s.substr(start, i - start + 1));
                dfs(i + 1, i + 1); // 下一个子串从 i+1 开始
                path.pop_back(); // 恢复现场
            }
        };
        dfs(0, 0);
        return ans;
    }

};
// @lc code=end

