/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 */
#include <algorithm>
#include <stack>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        if (n == 0) {
            return 0;
        }
        vector<int> f(n, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    f[i] = 2;
                    if (i - 2 > 0) {
                        f[i] += f[i - 2];
                    }
                } else if (i - f[i - 1] > 0 &&
                           s[i - f[i - 1] - 1] == '(') {
                    f[i] = f[i - 1] + 2;
                    if (i - f[i - 1] - 2 >= 0) {
                        f[i] += f[i - f[i - 1] - 2];
                    }
                }
            }
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end
