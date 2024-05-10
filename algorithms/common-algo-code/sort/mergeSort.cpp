#include <vector>
using namespace std;

vector<int> temp;

void merge(vector<int>& nums, int l, int mid, int r) {

    for(int i = l; i <= r; i++){
        temp[i] = nums[i];
    }

    int i = l, j = mid+1;
    for(int p = l; p <= r; p++) {
        if (i == mid + 1) {
            // 左半边数组已全部被合并
            nums[p] = temp[j++];
        } else if (j == r + 1) {
            // 右半边数组已全部被合并
            nums[p] = temp[i++];
        } else if (temp[i] > temp[j]) {
            nums[p] = temp[j++];
        } else {
            nums[p] = temp[i++];
        }
    }
}

void sort(vector<int>& nums, int l, int r){

    if(l == r) {
        return;
    }

    int mid = l + (r - l) / 2;

    sort(nums, l, mid);
    sort(nums, mid+1, r);
    merge(nums, l, mid, r);
}

void mergeSort(vector<int>& nums){

    temp = vector<int>(nums.size());
    sort(nums, 0, nums.size() - 1);
}

int main() {
    return 0;
}