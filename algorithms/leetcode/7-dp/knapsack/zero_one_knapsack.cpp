#include <vector>
#include <functional>
using namespace std;

//记忆化搜索
int zero_one_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
    function<int(int, int)> dfs = [&](int i, int c) {
        if(i < 0) return 0;
        if(memo[i][c] != -1) return memo[i][c];
        if(c < w[i]) //只能不选 
            return memo[i][c] = dfs(i-1, c);
        return memo[i][c] = max(dfs(i-1, c), dfs(i-1, c-w[i]) + v[i]); //选
    };
    return dfs(n-1, capacity);
};


// 改递推 1:1 翻译
// dfs(i, c) = dfs(i - 1, c) + dfs(i-1, c - w[i]) 
// f[i][c] = f[i - 1][c] + f[i-1][c - w[i]]
//      i = -1 负数下标，通过索引偏移处理
// f[i + 1][c] = f[i][c] + f[ijla[c - w[i]]]
int zero_one_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
    dp[0][0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(j >= w[i])
                dp[i+1][j] = max(dp[i][j], dp[i][j-w[i]] + v[i]);
            else {
                dp[i+1][j] = dp[i][j];
            }
        }
    return dp[n][capacity];
    }
}


// 状态压缩 两个数组
// i -> i+1 两个数组
// i+1 -> i+2 完全不会访问 i
// 所以i+2可以复用i
int zero_one_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(2, vector<int>(capacity+1, 0));
    dp[0][0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(j >= w[i])
                dp[(i+1) % 2][j] = max(dp[i % 2][j], dp[i % 2][j-w[i]] + v[i]);
            else {
                dp[(i+1) % 2][j] = dp[i % 2][j];
            }
        }
    return dp[n][capacity];
    }
}

// 状态压缩 一个数组
// 相当于 i 没了
// 横着看 j, j-w[i] -> j
// 从左到右遍历，不行，因为 j - w[i] 可能 等于 j + x - w[j]
    // 从左往右覆盖会导致后面的值依赖的前面值被当前值覆盖
// 但从右往左遍历，可以，因为不会覆盖前面的值
    // 当前值依赖的前面的值，不会我后面的值覆盖

int zero_one_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(2, vector<int>(capacity+1, 0));
    dp[0][0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
    for(int i = 0; i < n; i++) {
        for(int j = capacity; j >= 0; j--) {
            if(j >= w[i])
                dp[j] = max(dp[j], dp[j-w[i] + v[i]]);
            // else {
                // dp[j] = dp[j];
            // }
        }
    return dp[n][capacity];
    }
}