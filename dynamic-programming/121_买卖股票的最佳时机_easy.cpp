/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int> &prices) {
        int min_price = prices[0], max_profit = 0;
        int n = prices.size();
        for (int i = 1; i < n; i++) {
            min_price = min(min_price, prices[i]);
            max_profit = max(max_profit, prices[i] - min_price);
        }
        return max_profit;
    }
};
// @lc code=end
