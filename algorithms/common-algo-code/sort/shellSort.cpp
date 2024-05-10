#include <vector>
#include "common.cpp"
using namespace std;
void insertSort(vector<int>& A, int gap) {
    int n = A.size();
    for(int i = gap; i < n; i+=gap) {
        int v = A[i];
        int j = i - gap; 
        while(j >= 0 && A[j] > v) {
            A[j+gap] = A[j];
            j-=gap;
        }
        A[j+gap] = v;
    }
}

void shellSort(vector<int>& A, int gap) {
    int n = A.size();
    int cnt = 0;
    for(int i = )
}

int main() {
    vector<int> A{4,8,9,1,10,6,2,5,3,7};
    printArray(A);
    insertSort(A);
    printArray(A);
    return 0;
}