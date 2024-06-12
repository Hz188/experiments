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
        return dfs(num, 0, 0, path, n);
    }

private:
    bool isValidNumber(const string& str) {
        // Check if the number is within the range representable by long long
        if (str.size() > 19 || (str.size() == 19 && str > "9223372036854775807")) {
            return false;  // Bigger than LLONG_MAX
        }
        return true;
    }

    bool dfs(const string& num, int i, int start, vector<long long>& path, int n) {
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
        
        if (i - start > 0 && num[start] == '0') {
            return false; // invalid number if it starts with '0'
        }

        // Do not select current i
        if (i < n - 1) {
            if (dfs(num, i + 1, start, path, n)) {
                return true;
            }
        }

        // Select current i
        string s = num.substr(start, i - start + 1);
        if (!isValidNumber(s)) {
            return false; // If the number is invalid, skip it
        }
        
        long long digit = stoll(s);

        if (path.size() < 2 || digit == path.back() + path[path.size() - 2]) {
            path.push_back(digit);
            if (dfs(num, i + 1, i + 1, path, n)) {
                return true;
            }
            path.pop_back();
        }
        return false;
    }
};



// @lc code=end

