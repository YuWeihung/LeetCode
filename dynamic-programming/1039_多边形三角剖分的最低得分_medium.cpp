/*
 * @lc app=leetcode.cn id=1039 lang=cpp
 *
 * [1039] 多边形三角剖分的最低得分
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minScoreTriangulation(vector<int> &values) {
        int n = values.size();
        vector f(n, vector<int>(n));
        for (int i = n - 3; i >= 0; i--) {
            for (int j = i + 2; j < n; j++) {
                int res = INT_MAX;
                for (int k = i + 1; k < j; k++) {
                    res = min(res,
                              f[i][k] + f[k][j] +
                                  values[i] * values[k] * values[j]);
                }
                f[i][j] = res;
            }
        }
        return f[0][n - 1];
    }
};
// @lc code=end
