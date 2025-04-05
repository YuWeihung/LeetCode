/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <cmath>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n) {
        int m = (int)sqrt(n);
        vector f(m + 1, vector<int>(n + 1, INT_MAX));
        f[0][0] = 0;
        for (int i = 1; i <= m; i++) {
            for (int c = 0; c <= n; c++) {
                if (c < i * i) {
                    f[i][c] = f[i - 1][c];
                } else {
                    f[i][c] = min(f[i - 1][c], f[i][c - i * i] + 1);
                }
            }
        }
        return f[m][n];
    }
};
// @lc code=end
