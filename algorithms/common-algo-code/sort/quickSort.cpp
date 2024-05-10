#include <vector>
using namespace std;

int partition(vector<int>& nums, int lo, int hi) {
    int pivot = nums[lo];
    while(lo < hi) {
        while(lo < hi && nums[hi] > pivot){
            hi--;
        }
        nums[lo] = nums[hi]; //从后往前 找到一个比pivot小
        while(lo < hi && nums[lo] <= pivot){
            lo++;
        }
        nums[hi] = nums[lo]; // 从前往后 找到一个比pivot大的
    }
    nums[lo] = pivot;
    return lo;
}
void sort(vector<int>& nums, int lo, int hi) {
    if (lo >= hi) {
        return;
    }
    // 对 nums[lo..hi] 进行切分
    // 使得 nums[lo..p-1] <= nums[p] < nums[p+1..hi]
    int p = partition(nums, lo, hi);
    // 去左右子数组进行切分
    sort(nums, lo, p - 1);
    sort(nums, p + 1, hi);
}

void quickSort(vector<int>& nums){
    sort(nums, 0, nums.size() - 1);
}

int main() {
    return 0;
}