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
        int ans = 0;
        int l = requests.size();
        vector<int> path(n,0);
        //i表示当前遍历的元素，cnt是当前满足的请求
        function<void(int,int)> dfs = [&](int i, int cnt)
        {
            if(i == l){
                for(int k = 0;k < n;++k)
                    if(path[k] != 0) return;
                ans = max(ans,cnt);
                return;
            }
            //不选
            dfs(i + 1, cnt);
            //选
            path[requests[i][0]]--; //出去
            path[requests[i][1]]++; //进去
            dfs(i + 1, cnt + 1);
            //恢复现场
            path[requests[i][0]]++; //出去
            path[requests[i][1]]--; //进去
        };
        dfs(0, 0);
        return ans;
    }
};
// @lc code=end

