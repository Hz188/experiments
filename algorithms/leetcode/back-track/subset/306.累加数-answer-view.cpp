/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */

// @lc code=start
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        int n = num.size();
        vector<long long> path;
        return dfs(num, 0, path, n);
    }

private:
    bool isValidNumber(const string& str) {
        // Check if the number is within the range representable by long long
        if (str.size() > 19 || (str.size() == 19 && str > "9223372036854775807")) {
            return false;  // Bigger than LLONG_MAX
        }
        return true;
    }

    bool dfs(const string& num, int i, vector<long long>& path, int n) {
        if (i == n) {
            int m = path.size();
            if (m >= 3) {
                for (int j = 2; j < m; ++j) {
                    if (path[j] != path[j-1] + path[j-2]) {
                        return false;
                    }
                }
                return true;
            }
            return false;
        }

        int m = path.size();
        for (int j = i; j < n; ++j) {
            if (j - i > 0 && num[i] == '0') {
                continue; // skip numbers with leading zeros
            }

            string s = num.substr(i, j - i + 1);
            if (!isValidNumber(s)) {
                continue; // skip invalid numbers
            }

            long long digit = stoll(s);
            if (m <= 2 || digit == path[m-1] + path[m-2]) {
                path.push_back(digit);
                if (dfs(num, j + 1, path, n)) {
                    return true;
                }
                path.pop_back();
            }
        }
        return false;
    }
};

// @lc code=end

