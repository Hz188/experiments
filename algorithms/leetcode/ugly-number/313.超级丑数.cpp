/*
 * @lc app=leetcode.cn id=313 lang=cpp
 *
 * [313] 超级丑数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        int m = primes.size();
        vector<int> ps(m, 1);
        vector<long> prods(m, 1);

        vector<long> ugly(n + 1);
        ugly[1] = 1;

        int p = 2;
        while(p <= n) {
            long mn = INT_MAX;
            for(int i = 0; i < m; i++) {
                prods[i] = primes[i] * ugly[ps[i]];
                mn = min(mn, prods[i]);
            }
            ugly[p] = mn;
            p++;
            for(int i = 0; i < m; i++) {
                if (mn == prods[i]) {
                    ps[i]++;
                }
            }
        }
        return ugly[n];
    }
};
// @lc code=end

