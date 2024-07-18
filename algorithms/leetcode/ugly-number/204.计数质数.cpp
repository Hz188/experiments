/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    int countPrimes(int n) {
        vector<bool> isPrime(n, true); // vector instead of array
        for (int i = 2; i * i < n; i++)
            if (isPrime[i]) 
                for (int j = i * i; j < n; j += i)
                    isPrime[j] = false;

        int count = 0;
        for (int i = 2; i < n; i++)
            if (isPrime[i]) count++;

        return count;
    }
};
// @lc code=end

