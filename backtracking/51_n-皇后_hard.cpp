/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N 皇后
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<string>> ans;
    vector<int> queens;
    vector<int> col, diag1, diag2;

    void dfs(int r, int n) {
        if (r == n) {
            vector<string> board(n);
            for (int i = 0; i < n; i++) {
                board[i] = string(queens[i], '.') + 'Q' +
                           string(n - 1 - queens[i], '.');
            }
            ans.push_back(board);
            return;
        }
        for (int c = 0; c < n; c++) {
            int rc = r - c + n - 1;
            if (!col[c] && !diag1[r + c] && !diag2[rc]) {
                queens[r] = c;
                col[c] = diag1[r + c] = diag2[rc] = 1;
                dfs(r + 1, n);
                col[c] = diag1[r + c] = diag2[rc] = 0;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        queens.resize(n);
        col.resize(n);
        diag1.resize(2 * n - 1);
        diag2.resize(2 * n - 1);
        dfs(0, n);
        return ans;
    }
};
// @lc code=end
