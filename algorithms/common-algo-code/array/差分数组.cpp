# include <vector>
using namespace std;

vector<int> nums{1,2,3,4,5,6};
int n = nums.size();

vector<int> diff(n, 0);

int main(){

    // 得到差分数组
    diff[0] = nums[0];
    for (int i = 1; i < n; i++) {
        diff[i] = nums[i] - nums[i-1];
    }


    vector<int> res(n);

    // 功能1：恢复数组
    res[0] = diff[0];
    for(int i = 1; i < n; i++){
        res[i] = res[i-1] + diff[i];
    }

    // 功能2：操作区间[i...j]，改动值val
    int i, val, j;
    diff[i] += val;
    if (j + 1 < diff.size()) { 
        //这里有一个细节：如果j+1>=diff.size，说明对i...末尾所有元素进行操作，这时候就不需要逆操作了
        diff[j + 1] -= val;
    }

    return 0;
}


