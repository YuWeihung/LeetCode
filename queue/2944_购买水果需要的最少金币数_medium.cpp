/*
 * @lc app=leetcode.cn id=2944 lang=cpp
 *
 * [2944] 购买水果需要的最少金币数
 */
#include <climits>
#include <deque>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumCoins(vector<int> &prices) {
        int n = prices.size();
        deque<pair<int, int>> q;
        q.emplace_front(n + 1, 0);
        for (int i = n; i > 0; i--) {
            while (q.back().first > i * 2 + 1) {
                q.pop_back();
            }
            int f = prices[i - 1] + q.back().second;
            while (f <= q.front().second) {
                q.pop_front();
            }
            q.emplace_front(i, f);
        }
        return q.front().second;
    }
};
// @lc code=end
