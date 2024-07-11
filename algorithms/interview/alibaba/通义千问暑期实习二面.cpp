#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int compute(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0;
    int sum = 0;
    int maxFreq = 1;

    for (int right = 0; right < nums.size(); ++right) {
        sum += nums[right];
        while ((right - left + 1) * nums[right] - sum > k) {
            sum -= nums[left];
            left++;
        }
        maxFreq = max(maxFreq, right - left + 1);
    }

    return maxFreq;
}

int main() {
    vector<vector<int>> test_cases = {
        {1, 1, 2, 2},
        {1, 2, 4},
        {4, 8, 5, 3, 2},
        {5, 5, 5, 5, 5}
    };
    vector<int> ks = {1, 2, 3, 0};

    for (size_t i = 0; i < test_cases.size(); ++i) {
        cout << "For array: ";
        for (int num : test_cases[i]) {
            cout << num << " ";
        }
        cout << "with k = " << ks[i] << endl;
        cout << "Max frequency: " << compute(test_cases[i], ks[i]) << endl;
    }

    return 0;
}