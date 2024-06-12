/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */

// @lc code=start
#include <vector>
#include <string>
#include <functional>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        vector<int> path;
        // balance = 左括号个数 - 右括号个数
        function<void(int, int)> dfs = [&](int i, int balance) {
            if (path.size() == n) {
                string s(n * 2, ')');
                for (int j : path) s[j] = '(';
                ans.emplace_back(s);
                return;
            }
            // 可以填 0 到 balance 个右括号
            for (int close = 0; close <= balance; ++close) { // 填 close 个右括号
                path.push_back(i + close); // 填 1 个左括号
                dfs(i + close + 1, balance - close + 1);
                path.pop_back();
            }
        };
        dfs(0, 0);
        return ans;
    }
};
// @lc code=end

