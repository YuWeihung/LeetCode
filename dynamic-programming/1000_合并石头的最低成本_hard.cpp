/*
 * @lc app=leetcode.cn id=1000 lang=cpp
 *
 * [1000] 合并石头的最低成本
 */
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int mergeStones(vector<int> &stones, int k) {
        int n = stones.size();
        if ((n - 1) % (k - 1)) // 无法合并成一堆
            return -1;

        int s[n + 1];
        s[0] = 0;
        for (int i = 0; i < n; i++)
            s[i + 1] = s[i] + stones[i]; // 前缀和

        vector f(n, vector(n, vector<int>(k + 1)));
        for (int i = n - 1; i >= 0; i--) {
            f[i][i][1] = 0;
            for (int j = i + 1; j < n; j++) {
                for (int p = k; p >= 1; p--) {
                    if (p == 1) {
                        f[i][j][p] = f[i][j][k] + s[j + 1] - s[i];
                    } else {
                        int res = INT_MAX;
                        for (int m = i; m < j; m += k - 1) {
                            res = min(res, f[i][m][1] +
                                               f[m + 1][j][p - 1]);
                        }
                        f[i][j][p] = res;
                    }
                }
            }
        }

        return f[0][n - 1][1];
    }
};
// @lc code=end
