/*
 * @lc app=leetcode.cn id=1092 lang=cpp
 *
 * [1092] 最短公共超序列
 */

// @lc code=start
#include <string>
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n = s.size();
        int m = t.size();

        // 1. memo
        // 46/49 内存超过limit fail
        // vector<vector<string>> memo(n, vector<string>(m));
        // function<string(int, int)> dfs = [&] (int i, int j) {
        //     if(i < 0) return t.substr(0, j+1);
        //     if(j < 0) return s.substr(0, i+1);
        //     string& res = memo[i][j];
        //     if(!res.empty()) return res;
        //     if(s[i] == t[j]) {
        //         return res = dfs(i-1, j-1) + s[i];
        //     auto s1 = dfs(i-1, j) + s[i];
        //     auto s2 = dfs(i, j-1) + t[j];
        //     return res = s1.length() > s2.length() ? s2 : s1;
        // };
        // return dfs(n-1, m-1);

        // 1.1 看了题解 解决了内存超出问题 思路是一致的
        vector<vector<int>> memo(n, vector<int>(m, -1));
        // dfs(i,j) 返回 s 的前 i 个字母和 t 的前 j 个字母的最短公共超序列的长度
        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (i < 0) return j + 1; // s 是空串，返回剩余的 t 的长度
            if (j < 0) return i + 1; // t 是空串，返回剩余的 s 的长度
            int &res = memo[i][j];
            if (res != -1) return res; // 避免重复计算 dfs 的结果
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return res = dfs(i - 1, j - 1) + 1;
            return res = min(dfs(i - 1, j), dfs(i, j - 1)) + 1;
        };

        // make_ans(i,j) 返回 s 的前 i 个字母和 t 的前 j 个字母的最短公共超序列
        // 看上去和 dfs 没啥区别，但是末尾的递归是 if-else
        // make_ans(i-1,j) 和 make_ans(i,j-1) 不会都调用
        // 所以 make_ans 的递归树仅仅是一条链
        function<string(int, int)> make_ans = [&](int i, int j) -> string {
            if (i < 0) return t.substr(0, j + 1); // s 是空串，返回剩余的 t
            if (j < 0) return s.substr(0, i + 1); // t 是空串，返回剩余的 s
            if (s[i] == t[j]) // 最短公共超序列一定包含 s[i]
                return make_ans(i - 1, j - 1) + s[i];
            // 如果下面 if 成立，说明上面 dfs 中的 min 取的是 dfs(i - 1, j)
            // 说明 dfs(i - 1, j) 对应的公共超序列更短
            // 那么就在 make_ans(i - 1, j) 的结果后面加上 s[i]
            // 否则说明 dfs(i, j - 1) 对应的公共超序列更短
            // 那么就在 make_ans(i, j - 1) 的结果后面加上 t[j]
            if (dfs(i, j) == dfs(i - 1, j) + 1)
                return make_ans(i - 1, j) + s[i];
            return make_ans(i, j - 1) + t[j];
            // comment from ghz: 上面这个if else的出现导致我们两个递归只会选择其中一个，不再是之前的二叉树了，而是一条链，节约了一半的内存
        };

        return make_ans(n - 1, m - 1);

        
    }
};
// @lc code=end

