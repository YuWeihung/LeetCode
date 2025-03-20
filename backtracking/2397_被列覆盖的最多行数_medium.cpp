/*
 * @lc app=leetcode.cn id=2397 lang=cpp
 *
 * [2397] 被列覆盖的最多行数
 */
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ans;

    void dfs(int i,
             int selected,
             int covered,
             int m,
             int n,
             vector<vector<int>> &matrix,
             int numSelect,
             vector<int> &sum) {
        if (i == n || selected == numSelect) {
            ans = max(ans, covered);
            return;
        }
        dfs(i + 1, selected, covered, m, n, matrix, numSelect, sum);
        if (selected < numSelect) {
            selected++;
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == 1) {
                    sum[j]--;
                    if (sum[j] == 0) {
                        covered++;
                    }
                }
            }
            dfs(i + 1, selected, covered, m, n, matrix, numSelect,
                sum);
            for (int j = 0; j < m; j++) {
                if (matrix[j][i] == 1) {
                    sum[j]++;
                }
            }
        }
    }

    int maximumRows(vector<vector<int>> &matrix, int numSelect) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> sum(m, 0);
        int covered = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    sum[i]++;
                }
            }
            if (sum[i] == 0) {
                covered++;
            }
        }
        dfs(0, 0, covered, m, n, matrix, numSelect, sum);
        return ans;
    }
};
// @lc code=end
