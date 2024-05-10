#include <vector>
#include "common.cpp"
using namespace std;
void insertSort(vector<int>& A) {
    int n = A.size();
    for(int i = 1; i < n; i++) {
        int v = A[i];
        int j = i - 1; // j+1 = i 是未排序的第一个位置
        while(j >= 0 && A[j] > v) {
            A[j+1] = A[j];
            j--;
        }
        A[j+1] = v;
    }
}

int main() {
    vector<int> A{4, 3, 2, 5};
    printArray(A);
    insertSort(A);
    printArray(A);
    return 0;
}