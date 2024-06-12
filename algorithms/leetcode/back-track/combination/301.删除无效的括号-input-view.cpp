/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */

// @lc code=start
#include <vector>
#include <functional>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        int left = 0, right = 0;
        for(char c: s) {
            if(c == '(') 
                left++;
            else if(c ==')'){
                if(left == 0) right++;
                else left--;
            }
        }
        int n = s.length();
        unordered_set<string> set{};
        unordered_set<int> path{};
        function<void(int, int, int)> dfs = [&] (int index, int left, int right) {
            if(left == 0 && right == 0) {
                string res{};
                for(int i = 0; i < n; i++) {
                    if(!path.contains(i)) res += s[i];
                }
                if(is_valid(res)) set.insert(res);
                return;
            }
            if(left + right > n - index) return; //剩余字符数量无法凑够删除数量，直接return
            char c = s[index];
            if(c == '('  && left > 0) {//当前作为左括号的位置去掉
                path.insert(index);
                dfs(index+1, left-1, right);
                path.erase(index);
            } else if(c ==')' && right > 0) { //当前作为右括号的位置去掉
                path.insert(index);
                dfs(index+1, left, right-1);
                path.erase(index);
            }
            dfs(index + 1, left, right); // 左右都不删
        };
        dfs(0, left, right);
        vector<string> ans(set.begin(), set.end());
        return ans;
        
    }


    // 判断括号字符串是否有效
    bool is_valid(string& s) {
        int left = 0;
        for (char c : s) {
            if (c == '(') {
                left++;
            } else if (c == ')') {
                left--;
                if (left < 0) {
                    // 右括号比左括号多，肯定无效
                    return false;
                }
            }
        }
        // 如果左括号的数量等于右括号的数量，才是一个有效的括号字符串
        return left == 0;
    }
};

// @lc code=end

