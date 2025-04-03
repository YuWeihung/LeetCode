/*
 * @lc app=leetcode.cn id=2850 lang=cpp
 *
 * [2850] 将石头分散到网格图的最少移动次数
 */
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int ans = INT_MAX;
    void dfs(int k,
             int curSum,
             int toSize,
             vector<int> &visited,
             vector<vector<int>> &from,
             vector<vector<int>> &to) {
        if (k == toSize) // 选完了
        {
            ans = min(ans, curSum);
            return;
        }
        for (int j = 0; j < toSize; ++j) // from的k 和 to的j 配对
        {
            if (!visited[j]) {
                visited[j] = true;
                int d = abs(from[k][0] - to[j][0]) +
                        abs(from[k][1] - to[j][1]);
                dfs(k + 1, curSum + d, toSize, visited, from, to);
                visited[j] = false;
            }
        }
    }

    int minimumMoves(vector<vector<int>> &grid) {
        vector<vector<int>> from;
        vector<vector<int>> to;
        int m = grid.size();    // grid的行数
        int n = grid[0].size(); // grid的列数

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    to.push_back({i, j});
                if (grid[i][j] > 1) {
                    for (int k = 0; k < grid[i][j] - 1; ++k)
                        from.push_back({i, j});
                }
            }
        }
        int toSize =
            to.size(); // to数组的长度，和from数组的长度是一样的
        vector<int> visited(toSize, 0);

        dfs(0, 0, toSize, visited, from, to);
        return ans;
    }
};
// @lc code=end
