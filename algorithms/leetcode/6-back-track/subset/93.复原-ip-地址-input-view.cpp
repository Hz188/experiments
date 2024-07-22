// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem93.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
#include <vector>
#include <string>
#include <climits>
#include <functional>
using namespace std;

class Solution {
public:
    vector<string> ans;

    vector<string> restoreIpAddresses(string s) {
        dfs(0, 0, 0, "", s);
        return ans;
    }

    //num表示枚举到第几个整数了 num范围是{0，1，2，3}
    //left代表当前截断的起点
    //path保存之前枚举的结果
    //s即字符串
    void dfs(int num, int start, int i, string path, string& s) {
        //枚举结束，得到了一个IP地址
        if (num == 4) {
            //如果该IP地址完整，即使用了字符串里面的全部数字
            if (start == s.size()) {
                //去掉最后一个'.'字符
                //因为每次添加一个整数都是path+"整数."后面跟一个字符'.'
                path.pop_back();
                ans.push_back(path);
            }
            return;
        }

        if(i >= s.size()) return;
        if(s[start] != '0')  //如果是0则必须单选，不能继续后移
            // 如果没有这个判断，会导致重复
            dfs(num, start, i+1, path, s);

        if ((4 - num - 1) * 3 < s.size() - i - 1) return; //太多了
        if ((s.size() - i - 1) < 4 - num - 1) return; // 太少了 
        if (i - start + 1 > 3) return; // 当前选择大于3个了
        if(s[start] == '0'){
            dfs(num+1, start+1, start+1, path+"0.", s);
        } else {
            int data = stoi(s.substr(start, i - start + 1));
            if(data <= 255)
                dfs(num+1, i+1, i+1, path+s.substr(start, i - start + 1) + ".", s);
        }
    }
};
// @lc code=end
