#include <vector>
#include <iostream>
using namespace std;
void printArray(vector<int> &A)
{
    for (int i = 0; i < A.size(); i++)
    {
        cout << A[i];
        if (i == A.size() - 1)
        {
            cout << '\n';
        }
        else
        {
            cout << ",";
        }
    }
}