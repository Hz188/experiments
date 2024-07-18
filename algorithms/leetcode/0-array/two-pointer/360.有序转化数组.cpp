#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        // 双指针，相向而行，逼近对称轴
        int i = 0, j = nums.size() - 1;
        // 如果开口朝上，越靠近对称轴函数值越小
        // 如果开口朝下，越靠近对称轴函数值越大
        int p = a > 0 ? nums.size() - 1 : 0;
        vector<int> res(nums.size());
        // 执行合并两个有序数组的逻辑
        while (i <= j) {
            int v1 = f(nums[i], a, b, c);
            int v2 = f(nums[j], a, b, c);
            if (a > 0) {
                // 如果开口朝上，越靠近对称轴函数值越小
                if (v1 > v2) {
                    res[p--] = v1;
                    i++;
                } else {
                    res[p--] = v2;
                    j--;
                }
            } else {
                // 如果开口朝下，越靠近对称轴函数值越大
                if (v1 > v2) {
                    res[p++] = v2;
                    j--;
                } else {
                    res[p++] = v1;
                    i++;
                }
            }
        }
        return res;
    }

    int f(int x, int a, int b, int c) {
        return a*x*x + b*x + c;
    }
};