#include <vector>
#include "common.cpp"

using namespace std;
int bubbleSort(vector<int>& A) {
    int n = A.size();
    int sw = 0;
    for(int i = 0; i < n; i++) { // i 未排序的开头
        for(int j = n-2; j >= i; j--) { // 一轮排序有序一个元素，所以i++之后，不需要对i之前的再排序了
            if(A[j] > A[j+1]){
                swap(A[j], A[j+1]);
                sw++;
            }
        }
    }
    return sw;
}

int main() {
    vector<int> A{4, 3, 2, 5};
    printArray(A);
    bubbleSort(A);
    printArray(A);
    return 0;
}