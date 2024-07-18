/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
#include <stack>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> matched{
            {')','('},
            {'}','{'},
            {']','['}
        };
        stack<char> left{};
        for(char c: s) {
            if(c == '(' || c == '{' || c == '['){
                left.push(c);
            } else {
                if(!left.empty() && matched[c] == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        return left.empty();
    }
};
// @lc code=end

