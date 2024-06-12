#include <vector>
#include <functional>
using namespace std;

class Solution {
public:
    int perfectMenu(vector<int>& materials,  // 食材数量
                    vector<vector<int>>& cookbooks, // cookboos[i][j] 料理i需要的食材j
                    vector<vector<int>>& attribute, // attribute[i] = {x, y} 料理i的美味度x，饱腹感y
                    int limit) { //饱腹感 >= limit

        int ans {-1}; 
        int m = materials.size(); // m种食材
        int n = cookbooks.size(); // n种料理
        function<void(int, int, int)> dfs = [&] (int start, int limit, int delicious) { //当前子问题：start开始选择料理
            if(limit <= 0) {
                // cout << ans << endl;
                ans = max(ans, delicious);
            }
            if(start == n) return;

            //当前操作：选一个可以做的料理
            for(int i = start; i < n; i++) {
                //检查当前料理是否可以做
                int k = 0;
                while(k < m){
                    if(materials[k] - cookbooks[i][k] < 0) {
                        break;
                    }
                    k++;
                }
                if(k < m) {
                    continue; // k < m说明break触发了，当前料理不可做，continue到下一个料理
                }
                for(int j = 0; j < m; j++) materials[j] -= cookbooks[i][j];
                dfs(i+1, limit - attribute[i][1], delicious + attribute[i][0]); //下一个子问题：从i+1开始选择料理
                for(int j = 0; j < m; j++) materials[j] += cookbooks[i][j];
            }
        };
        dfs(0, limit, 0);
        return ans;
    }

};