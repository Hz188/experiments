/*
 * @lc app=leetcode.cn id=1458 lang=cpp
 *
 * [1458] 两个子序列的最大点积
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // 1. memo
        // vector<vector<int>> memo(n, vector<int>(m, -1));
        // function<int(int, int)> dfs = [&] (int i, int j) {
        //     if(i == 0){
        //         return max(
        //             nums1[0] * (*max_element(nums2.begin(), nums2.begin() + j+1)),
        //             nums1[0] * (*min_element(nums2.begin(), nums2.begin() + j+1))
        //         );
        //     }
        //     if(j == 0) {
        //         return max(
        //             nums2[0] * (*max_element(nums1.begin(), nums1.begin() + i+1)),
        //             nums2[0] * (*min_element(nums1.begin(), nums1.begin() + i+1))
        //         );
        //     }
        //     int& res = memo[i][j];
        //     if(res != -1) return res;
        //     if(nums1[i]*nums2[j] < 0) {
        //         return res = max(dfs(i-1, j), dfs(i, j-1));
        //     }
        //     return res = max(
        //                     max(
        //                         dfs(i-1, j), 
        //                         max(
        //                             dfs(i, j-1),
        //                             dfs(i-1, j-1) + nums1[i]*nums2[j]
        //                         )
        //                     ),
        //                     nums1[i]*nums2[j] //前置全为负，舍弃
        //     );
        // };
        // return dfs(n-1, m-1);

        // 2. dp
        vector<vector<int>> f(n, vector<int>(m, -1));
        f[0][0] = nums1[0]*nums2[0];
        for(int i = 1; i < m; i++) {
            f[0][i] = max(f[0][i-1], nums1[0]*nums2[i]);
        }

        for(int i = 1; i < n; i++) {
            f[i][0] = max(f[i-1][0], nums1[i]*nums2[0]);
            for(int j = 1; j < m; j++) {
                int p = nums1[i] * nums2[j];
                f[i][j] = max(f[i-1][j], f[i][j-1]);
                f[i][j] = max(f[i][j], f[i-1][j-1] + p);
                f[i][j] = max(f[i][j], p); // 前面全是负的话，肯定更小，直接舍弃，相当于0 + p
            }
        }
        return f[n-1][m-1];
    }


};
// @lc code=end

