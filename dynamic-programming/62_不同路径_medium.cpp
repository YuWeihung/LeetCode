/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector f(m + 1, vector<int>(n + 1));
        f[0][1] = 1;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f[i + 1][j + 1] = f[i + 1][j] + f[i][j + 1];
            }
        }
        return f[m][n];
    }
};
// @lc code=end
