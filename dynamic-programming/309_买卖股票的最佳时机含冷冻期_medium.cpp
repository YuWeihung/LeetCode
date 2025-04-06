/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int n = prices.size();
        vector f(n + 2, vector<int>(2));
        f[1][1] = INT_MIN;
        for (int i = 0; i < n; i++) {
            // i 天不持有股票，可能 i - 1 天不持有股票或 i -
            // 1天持有股票 i 天卖出
            f[i + 2][0] = max(f[i + 1][0], f[i + 1][1] + prices[i]);
            // i 天持有股票，可能 i - 1 天持有股票
            // 或 i - 1天不持有股票 i 天买入
            // 或 i - 2天持有股票但卖出 i 天再买入。其中后两者相等。
            f[i + 2][1] = max(f[i + 1][1], f[i][0] - prices[i]);
        }
        return f[n + 1][0];
    }
};
// @lc code=end
