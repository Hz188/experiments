#include <vector>
#include <functional>
using namespace std;

//记忆化搜索
int unbounded_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> memo(n, vector<int>(capacity + 1, -1));
    function<int(int, int)> dfs = [&](int i, int c) {
        if(i < 0) return 0;
        if(memo[i][c] != -1) return memo[i][c];
        if(c < w[i]) //只能不选 
            return memo[i][c] = dfs(i-1, c);
        return memo[i][c] = max(dfs(i-1, c), dfs(i, c-w[i]) + v[i]); //选
    };
    return dfs(n-1, capacity);
};


// 改递推 1:1 翻译
// dfs(i, c) = dfs(i - 1, c) + dfs(i-1, c - w[i]) 
// f[i][c] = f[i - 1][c] + f[i][c - w[i]]
//      i = -1 负数下标，通过索引偏移处理
// f[i + 1][c] = f[i][c] + f[i+1][c - w[i]]]
int unbounded_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(n+1, vector<int>(capacity+1, 0));
    dp[0][0] = 0; // 对应于dfs中 i == -1 （因为数组下标都加了1）
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(j >= w[i])
                dp[i+1][j] = max(dp[i][j], dp[i+1][j-w[i]] + v[i]);
            else {
                dp[i+1][j] = dp[i][j];
            }
        }
    }
    return dp[n][capacity];
}


// 状态压缩 两个数组
// i -> i+1 两个数组
// i+1 -> i+2 完全不会访问 i
// 所以i+2可以复用i
int unbounded_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<vector<int>> dp(2, vector<int>(capacity+1, 0));
    dp[0][0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(j >= w[i])
                dp[(i+1) % 2][j] = min(dp[i % 2][j], dp[(i+1) % 2][j-w[i]]+v[i]);
            else {
                dp[(i+1) % 2][j] = dp[i % 2][j];
            }
        }
    return dp[n%2][capacity];
    }
}

// 状态压缩 一个数组
// 相当于 i 没了
// 横着看 j, j-w[i] -> j
// 需要正序遍历，具体分析看README
int unbounded_knapsack(int capacity, vector<int>& w, vector<int>& v) {
    int n = w.size();
    vector<int> dp(capacity+1, 0);
    dp[0] = 1; // 对应于dfs中 i == -1 （因为数组下标都加了1）
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= capacity; j++) {
            if(j >= w[i])
                dp[j] = max(dp[j], dp[j-w[i]] + v[i]);
            // else {
                // dp[j] = dp[j];
            // }
        }
    return dp[capacity];
    }
}