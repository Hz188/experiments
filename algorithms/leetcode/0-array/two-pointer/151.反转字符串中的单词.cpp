/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
#include <string>
#include <sstream>
using namespace std;
// 注意：cpp 代码由 chatGPT🤖 根据我的 java 代码翻译，旨在帮助不同背景的读者理解算法逻辑。
// 本代码已经通过力扣的测试用例，应该可直接成功提交。

class Solution
{
public:
    string reverseWords(string s)
    {
        int i, j;
        i = s.size() - 1;
        j = i;
        string res;
        while (i >= 0){
            while (i >= 0 && s[i] != ' ')
                i--;

            if (i != j)
                res.append(s.substr(i + 1, (j - i)) + " ");

            while (i >= 0 && s[i] == ' '){
                i--;
                j = i;
            }
        }
        res.pop_back();
        return res;
    }
};
// @lc code=end
