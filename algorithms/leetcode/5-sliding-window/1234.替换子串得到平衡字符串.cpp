/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    int balancedString(string s) {
        int n = s.length(), m = n / 4, cnt['X']{}; // 也可以用哈希表，不过数组更快一些
        for (char c : s) ++cnt[c];
        if (cnt['Q'] == m && cnt['W'] == m && cnt['E'] == m && cnt['R'] == m)
            return 0; // 已经符合要求
        int ans = n, left = 0;
        for (int right = 0; right < n; right++) { // 枚举子串右端点
            int c = s[right];
            cnt[c]--; // [left, right] 是当前双指针对应的子串
            // 然后将其频数减掉，得到的是子串外的剩余字符的频数
            // 这个时候如果都小于等于m，那么就可以填满，此时ans=right-left+1
            // 如果有一个字符大于m，也就是说，你超出范围了，无法通过当前[left,right]子串完成替换，必须接着迭代
            while (cnt['Q'] <= m && cnt['W'] <= m && cnt['E'] <= m && cnt['R'] <= m) {
                ans = min(ans, right - left + 1);
                int d = s[left];
                cnt[d]++; // 缩小子串
                left++;
            }
        }
        return ans;
    }

    int another_solve(string s) {
        //上面的方法是反向思考，看子串外字符的情况，这里也可以统计子串内的情况
        int n = s.size();
        vector<int> cnt('X', 0);
        for(char& c: s) cnt[c]++;
        //统计频数后，可以知道多了的字符需要换掉多少个
        int diffQ = cnt['Q'] - n/4;
        int diffW = cnt['W'] - n/4;
        int diffE = cnt['E'] - n/4;
        int diffR = cnt['R'] - n/4;
        if(diffQ == 0 && diffW == 0 && diffE == 0 && diffR == 0)
            return 0;
        int res = n; //最大整个串全换了
        vector<int> subcnt('X',0);
        for(int left = 0, right = 0; right < n; ++right){
            subcnt[s[right]]++;
            //这里意思是：当前子串的各个位置足够拿来替换了
            // 举个简单的例子，Q多两个，R少两个
            // 现在[left, right] 子串中，Q够两个了
            // 那么我们就可以认为这两个Q就是多的那两个，可以把它换掉，所以记录答案
            while(subcnt['Q'] >= diffQ && 
                    subcnt['W'] >= diffW && 
                    subcnt['E'] >= diffE && 
                    subcnt['R'] >= diffR) {
                res = min(res, right - left + 1); // 当然，还会有别的[left,right]子串的情况满足Q够两个，所以取最短
                subcnt[s[left]]--;
                left++;
            }
        }
        return res;
    }
};
// @lc code=end

