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
        int profit = 0;
        int buyPrice = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < buyPrice) {
                buyPrice = prices[i];
            }
            if (prices[i] - buyPrice > profit) {
                profit = prices[i] - buyPrice;
            }
        }
        return profit;
    }
};
// @lc code=end
