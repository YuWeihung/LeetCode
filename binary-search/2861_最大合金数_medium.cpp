/*
 * @lc app=leetcode.cn id=2861 lang=cpp
 *
 * [2861] 最大合金数
 */
#include <vector>

using namespace std;

// check() true 满足
// left - 1 满足 right + 1 不满足

// @lc code=start
class Solution {
public:
    bool check(int n,
               int k,
               int budget,
               vector<vector<int>> &composition,
               vector<int> &stock,
               vector<int> &cost,
               long long ans) {
        for (int i = 0; i < k; i++) {
            long long money = 0;
            for (int j = 0; j < n; j++) {
                long long need = ans * composition[i][j];
                if (need > stock[j]) {
                    money += (need - stock[j]) * cost[j];
                }
            }
            if (money <= budget) {
                return true;
            }
        }
        return false;
    }

    int maxNumberOfAlloys(int n,
                          int k,
                          int budget,
                          vector<vector<int>> &composition,
                          vector<int> &stock,
                          vector<int> &cost) {
        int left = 1,
            right = *min_element(stock.begin(), stock.end()) + budget;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(n, k, budget, composition, stock, cost, mid)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end
