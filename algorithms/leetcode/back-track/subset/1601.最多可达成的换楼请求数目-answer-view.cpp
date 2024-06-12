/*
 * @lc app=leetcode.cn id=1601 lang=cpp
 *
 * [1601] 最多可达成的换楼请求数目
 */

// @lc code=start
#include <vector>
#include <functional>
using namespace std;
class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& requests) {
        vector<int> path(n,0);
        int l = requests.size();
        int ans = 0;
        auto check = [&]() {
            for(int k = 0;k < n;++k)
                if(path[k] != 0) return false;
            return true;
        };
        function<void(int,int)> dfs = [&](int i,int cnt) {
            //每个节点都可能是答案，所以在这里要判断
            if(check()) ans = max(ans, cnt);
            if(i == l)
                return;
            for(int j = i;j < l;++j) {
                path[requests[j][0]]--;
                path[requests[j][1]]++;
                dfs(j+1, cnt+1);
                path[requests[j][0]]++;
                path[requests[j][1]]--;
            }
        };
        dfs(0, 0);
        return ans;
    }
};
// @lc code=end

