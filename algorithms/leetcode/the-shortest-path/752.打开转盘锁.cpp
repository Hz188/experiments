/*
 * @lc app=leetcode.cn id=752 lang=cpp
 *
 * [752] 打开转盘锁
 */

// @lc code=start
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
using namespace std;
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited(deadends.begin(), deadends.end());
        if(visited.count("0000")) 
            return -1;
        queue<string> q{};
        q.push("0000");
        visited.insert("0000");
        int step = 0;
        while (!q.empty()) {
            for (int i = q.size(); i > 0; i--) {
                string cur = q.front(); q.pop();

                /* 判断是否到达终点 */
                if (cur == target)
                    return step;

                /* 将一个节点的未遍历相邻节点加入队列 */
                for (int j = 0; j < 4; j++) {
                    string up = plusOne(cur, j);
                    if (!visited.count(up)) {
                        q.push(up);
                        visited.insert(up);
                    }
                    string down = minusOne(cur, j);
                    if (!visited.count(down)) {
                        q.push(down);
                        visited.insert(down);
                    }
                }
            }
            /* 在这里增加步数 */
            step++;
        }
        return -1;
    }
    // 将 s[j] 向上拨动一次
    string plusOne(string s, int j) {
        if (s[j] == '9') s[j] = '0';
        else s[j] += 1;
        return s;
    }

    // 将 s[i] 向下拨动一次
    string minusOne(string s, int j) {
        if (s[j] == '0') s[j] = '9';
        else s[j] -= 1;
        return s;
    }
};
// @lc code=end

