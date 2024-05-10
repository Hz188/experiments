#include <vector>
#include "common.cpp"

using namespace std;
void selectSort(vector<int>& A) {
    int n = A.size();
    int sw = 0;
    for(int i = 0; i < n; i++) { 
        int minj = i;
        for(int j = i+1; j < n; j++) { 
            if(A[j] < A[minj])
                minj = j;
        }
        swap(A[minj], A[i]);
    }
}

int main() {
    vector<int> A{4, 3, 2, 5, 1, 4, 9};
    printArray(A);
    selectSort(A);
    printArray(A);
    return 0;
}