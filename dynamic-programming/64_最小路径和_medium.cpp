/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 */
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>> &grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m + 1, vector<int>(n + 1, INT_MAX));
        f[0][1] = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                f[i + 1][j + 1] =
                    min(f[i + 1][j], f[i][j + 1]) + grid[i][j];
            }
        }
        return f[m][n];
    }
};
// @lc code=end
