/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        int n = coins.size();
        vector f(n + 1, vector<int>(amount + 1, INT_MAX / 2));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c < coins[i]) {
                    f[i + 1][c] = f[i][c];
                } else {
                    f[i + 1][c] =
                        min(f[i][c], f[i + 1][c - coins[i]] + 1);
                }
            }
        }
        int ans = f[n][amount];
        return ans < INT_MAX / 2 ? ans : -1;
    }
};
// @lc code=end
