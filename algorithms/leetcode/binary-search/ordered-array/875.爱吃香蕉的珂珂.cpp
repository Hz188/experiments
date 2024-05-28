// @before-stub-for-debug-begin
#include <vector>
#include <string>
#include "commoncppproblem875.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */

// @lc code=start
#include <vector>
#include <numeric>
using namespace std;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l <= r) {
            int mid = (r-l)/2 + l;
            long long d = 0;
            for(const int& p: piles) {
                d += (p - 1) / mid + 1;
            }
            if(d <= h) { // true 能吃完
                r = mid-1; // [r+1...] blue
            } else { // d > h 吃不完 false
                l = mid+1; //[...l-1] red
            }
        }
        // l = r+1
        return l;
    }
};
// @lc code=end

