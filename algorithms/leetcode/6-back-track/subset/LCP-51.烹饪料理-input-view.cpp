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
        function<void(int, int, int)> dfs = [&] (int i, int limit, int delicious) { //当前子问题：从i开始或不选
            if(limit <= 0) {
                ans = max(ans, delicious);
            }
            if(i == n) return;
            //当前操作：料理i选或者不选

            //不做
            dfs(i+1, limit, delicious);

            //检查当前料理是否可以做
            for(int j = 0; j < m; j++){
                if(materials[j] - cookbooks[i][j] < 0)
                    return;
            }
            //做
            for(int j = 0; j < m; j++) materials[j] -= cookbooks[i][j];
            dfs(i+1, limit - attribute[i][1], delicious + attribute[i][0]);  //下一个子问题：料理i+1选或不选
            for(int j = 0; j < m; j++) materials[j] += cookbooks[i][j];
        };
        dfs(0, limit, 0);
        return ans;
    }

};