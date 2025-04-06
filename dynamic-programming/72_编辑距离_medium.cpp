/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        vector f(n + 1, vector<int>(m + 1));
        for (int i = 0; i <= n; i++) {
            f[i][0] = i;
        }
        for (int j = 0; j <= m; j++) {
            f[0][j] = j;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (word1[i] == word2[j]) {
                    f[i + 1][j + 1] = f[i][j];
                } else {
                    f[i + 1][j + 1] =
                        min({f[i + 1][j], f[i][j + 1], f[i][j]}) + 1;
                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end
