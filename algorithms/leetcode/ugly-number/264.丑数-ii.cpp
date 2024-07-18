/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */

// @lc code=start
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        int p2 = 1, p3 = 1, p5 = 1;
        int product2 = 1, product3 = 1, product5 = 1;

        vector<int> ugly(n + 1);
        ugly[1] = 1;

        int p = 2;
        while(p <= n) {
            product2 = 2 * ugly[p2];
            product3 = 3 * ugly[p3];
            product5 = 5 * ugly[p5];
            int mn = min({product2, product3, product5});
            ugly[p] = mn;
            p++;
            if(mn == product2) {
                p2++;
            }
            if(mn == product3) {
                p3++;
            }
            if(mn == product5) {
                p5++;
            }
        }
        return ugly[n];
    }
};
// @lc code=end

