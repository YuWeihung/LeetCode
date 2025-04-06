/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(int k, vector<int> &prices) {
        int n = prices.size();
        vector<vector<vector<int>>> f(
            n + 1, vector(k + 2, vector<int>(2, INT_MIN / 2)));
        for (int j = 1; j < k + 2; j++) {
            f[0][j][0] = 0;
        }
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < k + 2; j++) {
                f[i + 1][j][0] =
                    max(f[i][j][0], f[i][j - 1][1] + prices[i]);
                f[i + 1][j][1] =
                    max(f[i][j][1], f[i][j][0] - prices[i]);
            }
        }
        return f[n][k + 1][0];
    }
};
// @lc code=end
