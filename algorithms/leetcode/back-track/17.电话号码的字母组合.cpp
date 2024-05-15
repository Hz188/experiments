/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */

// @lc code=start
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    unordered_map<int, string> MAPPING{
        {0, ""},
        {1, ""},
        {2, "abc"},
        {3, "def"},
        {4, "ghi"},
        {5, "jkl"},
        {6, "mno"},
        {7, "pqrs"},
        {8, "tuv"},
        {9, "wxyz"},
    };
public:
    vector<string> letterCombinations(string digits) {
        n = digits.size();
        if(digits.empty()) 
            return {};
        back_track(digits, 0);
        return ans;
    }
    int n{};
    vector<string> ans{};
    string path{};
    void back_track(string& digits, int i){
        if(i == n) {
            ans.push_back(path);
            return;
        }
        int digit = digits[i] - '0';
        for(char c: MAPPING[digit]) {
            path.push_back(c);
            back_track(digits, i+1);
            path.pop_back();
        }

    }
};
// @lc code=end

