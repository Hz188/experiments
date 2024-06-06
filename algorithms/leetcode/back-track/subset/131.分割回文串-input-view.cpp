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
    vector<vector<string>> partition(string s) {

        vector<vector<string>> ans;
        vector<string> path;
        int n = s.length();

        // 输入视角：第i个字符我们选不选入当前回文串
        // start 表示当前这段回文子串的开始位置，i表示我们当前要选择的字符
        // 也就是[start...i]作为我们当前要判定的回文串
        function<void(int, int)> dfs = [&](int i, int start) {
            if (i == n) {
                ans.emplace_back(path);
                return;
            }
            // 第i个我们不选
            // 注意：第n-1是最后一个，必须要选了
            if (i < n - 1)
                dfs(i + 1, start); // [start...i+1]是我们当前的选择

            // 第i个我们选了, s[i]作为了当前子串的最后一个字符
            if (isPalindrome(s, start, i)) { //进行一次判定
                path.push_back(s.substr(start, i - start + 1)); // [start...i]判定完了，下一个就是i+1开始，i+1结束作为选择
                dfs(i + 1, i + 1); // 下一个子串从 i+1 开始
                path.pop_back(); // 恢复现场
            }
        };
        dfs(0, 0);
        return ans;
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

