/*
 * @lc app=leetcode.cn id=710 lang=cpp
 *
 * [710] 黑名单中的随机数
 */

// @lc code=start
#include <vector>
#include <unordered_map>
using namespace std;
class Solution {
private:
    unordered_map<int, int> val_to_index{};
    int valid_size{};
public:
    Solution(int n, vector<int>& blacklist) {
        valid_size = n - blacklist.size();
        for(int b: blacklist) {
            val_to_index[b] = -1;
        }
        int last = n - 1;
        for(int b: blacklist) {
            if(b >= valid_size) {
                continue;
            }
            while(val_to_index.contains(last)) {  // 看看last处的值是不是黑名单
                last--;
            }
            val_to_index[b] = last;  //相当于把前面的在valid_size内的黑名单的值映射到了后面的白名单值
            last--;
        }
    }
    
    int pick() {
        int index = rand() % valid_size;
        if(val_to_index.contains(index)) {
            return val_to_index[index];
        }
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(n, blacklist);
 * int param_1 = obj->pick();
 */
// @lc code=end

