/*
*  W的背包，N个物品，价值v，重量w，尽可能价值最大就是背包
*/

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){

    //W, N, v, w
    int W, N, v[N], w[N];
    int dp[N+1][W+1];

    // dp[0][...] = 0
    // dp[...][0] = 0

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= W; j++) {
            //做选择：装i或者不装i （第i个物品，索引是i-1)
            if(j - w[i] >= 0){
                dp[i][j] = max(
                    dp[i-1][j],
                    dp[i-1][j - w[i-1]] + v[i-1]
                );
            } else {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    return dp[N][W];

}


//递归写法
// dp(w, v, N, W);
vector<vector<int>> memo;//[N+1][C+1]的shape

// 用 [0...index]的物品,填充容积为c的背包的最大价值
int dp(const vector<int> &w, const vector<int> &v, int index, int c){

    if(c <= 0 || index < 0)
        return 0;

    if(memo[index][c] != -1)
        return memo[index][c];

    int res = dp(w, v, index-1, c);
    if(c >= w[index])
        res = std::max(res, v[index] + dp(w, v, index - 1, c - w[index]));
    memo[index][c] = res;
    return res;
}


//子集背包
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num : nums) sum += num;
    // 和为奇数时，不可能划分成两个和相等的集合
    if (sum % 2 != 0) return false;
    int n = nums.size();
    sum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1));
    // base case
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0) {
                // 背包容量不足，不能装入第 i 个物品
                dp[i][j] = dp[i - 1][j];
            } else {
                // 装入或不装入背包
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }
    return dp[n][sum];
}


//完全背包
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        // base case
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++)
                if (j - coins[i-1] >= 0)
                    dp[i][j] = dp[i - 1][j]
                            + dp[i][j - coins[i-1]];
                else
                    dp[i][j] = dp[i - 1][j];
        }
        return dp[n][amount];
    }
};