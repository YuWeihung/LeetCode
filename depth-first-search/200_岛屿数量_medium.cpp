/*
 * @lc app=leetcode.cn id=200 lang=cpp
 *
 * [200] 岛屿数量
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    const int DIRS[4][2] = {
        { 0,  1},
        { 0, -1},
        { 1,  0},
        {-1,  0}
    };
    int numIslands(vector<vector<char>> &grid) {
        int ans = 0;
        int m = grid.size(), n = grid[0].size();
        auto dfs = [&](auto &&dfs, int i, int j) {
            if (i < 0 || i >= m || j < 0 || j >= n ||
                grid[i][j] != '1') {
                return;
            }
            grid[i][j] = '2';
            for (auto &[dx, dy] : DIRS) {
                int x = i + dx;
                int y = j + dy;
                dfs(dfs, x, y);
            }
        };
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    dfs(dfs, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
