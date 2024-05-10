# include <vector>
using namespace std;

vector<int> nums{1,2,3,4,5,6};
int n = nums.size();

vector<int> presum(n+1, 0);

int main(){

    // 得到前缀和数组
    for (int i = 0; i < n; i++) {
        presum[i+1] = presum[i] + nums[i];
    }

    // 使用前缀和数组：求[i,j]的和
    int i, j;
    int sum_i_j = presum[j+1] - presum[i];

    return 0;
}


