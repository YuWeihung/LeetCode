/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N 皇后 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int ans;
    vector<int> queens;
    vector<int> col, diag1, diag2;

    void dfs(int r, int n) {
        if (r == n) {
            ans++;
            return;
        }
        for (int c = 0; c < n; c++) {
            int rc = c - r + n - 1;
            if (!col[c] && !diag1[r + c] && !diag2[rc]) {
                queens[r] = c;
                col[c] = diag1[r + c] = diag2[rc] = 1;
                dfs(r + 1, n);
                col[c] = diag1[r + c] = diag2[rc] = 0;
            }
        }
    }

    int totalNQueens(int n) {
        queens.resize(n);
        col.resize(n);
        diag1.resize(2 * n - 1);
        diag2.resize(2 * n - 1);
        dfs(0, n);
        return ans;
    }
};
// @lc code=end
