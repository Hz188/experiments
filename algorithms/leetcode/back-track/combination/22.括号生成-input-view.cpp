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

        int m = 2 * n;
        vector<string> ans{};
        string path(m, 'a');
        function<void(int, int)> dfs = [&](int i, int left){
            if(i == m){
                ans.push_back(path);
                return;
            }
            // [0...i) 中i目前还没放
            // '(' 个数 = left
            // ')' 个数 = i - left
            if(left < n){  //还有左括号可以放
                path[i] = '(';
                dfs(i+1, left+1);
            }
            if(i - left < left) {  
            //这个判断条件的意思是已经放的右小于左，说明括号还没完全闭合，可以接着放右
                path[i] = ')';
                dfs(i+1, left);
            }
        };
        dfs(0, 0);//现在放了0个右，0个左
        return ans;
    }
};
// @lc code=end

