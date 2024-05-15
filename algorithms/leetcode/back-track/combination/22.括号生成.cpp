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
        //为什么能看做组合，其实等价于2n个位置选n个放左括号，其余位置放右括号
        //第i个位置，选或不选两种选项(不选其实相当于选了右括号)
        int m = 2 * n;
        vector<string> ans{};
        string path(m, 'a');
        function<void(int, int)> dfs = [&](int i, int open){
            if(i == m){
                ans.push_back(path);
                return;
            }
            if(open < n){
                path[i] = '(';
                dfs(i+1, open+1);
            }
            if(i - open < open) {
                path[i] = ')';
                dfs(i+1, open);
            }
        };
        dfs(0, 0);//现在放了0个右，0个左
        return ans;
    }
};
// @lc code=end

