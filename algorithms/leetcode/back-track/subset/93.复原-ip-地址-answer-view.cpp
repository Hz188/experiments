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
        dfs(0, 0, "", s);
        return ans;
    }

    //num表示枚举到第几个整数了 num范围是{0，1，2，3}
    //left代表当前截断的起点
    //path保存之前枚举的结果
    //s即字符串
    void dfs(int num, int left, string path, string& s) {
        //枚举结束，得到了一个IP地址
        if (num == 4) {
            //如果该IP地址完整，即使用了字符串里面的全部数字
            if (left == s.size()) {
                //去掉最后一个'.'字符
                //因为每次添加一个整数都是path+"整数."后面跟一个字符'.'
                path.pop_back();
                ans.push_back(path);
            }

            return;
        }

        //从当前开始依次枚举
        //[left,left+0]，[left,left+1]，[left,left+2]这个三个子字符串作为整数
        for (int i = 0; i < 3; i++) {
            int right = left + i;
            //剪枝，举个例子
            //第一个整数只选2，"2."
            //剩下三个整数无论怎么选，最大只能"2.552.551.113"也用不完所有数
            //因此无法满足直接跳过该情况
            if ((4 - num - 1) * 3 < s.size() - right - 1)continue;

            //防止越界
            if (right >= s.size())break;

            //如果该整数起点为0，则只能选0
            if (s[left] == '0') {
                dfs(num + 1, left + 1, path + "0.", s);
                //跳出循环
                break;
            }
            //正常情况
            else {
                //获取所要整数
                int data = stoi(s.substr(left, right - left + 1));
                //判断是否合法
                if (data <= 255)
                    dfs(num + 1, right + 1, path + s.substr(left, right - left + 1) + ".", s);
            }
        }


    }
};

// @lc code=end

