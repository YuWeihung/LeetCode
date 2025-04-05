/*
 * @lc app=leetcode.cn id=518 lang=cpp
 *
 * [518] 零钱兑换 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int change(int amount, vector<int> &coins) {
        int n = coins.size();
        vector<vector<unsigned>> f(n + 1,
                                   vector<unsigned>(amount + 1));
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= amount; c++) {
                if (c < coins[i]) {
                    f[i + 1][c] = f[i][c];
                } else {
                    f[i + 1][c] = f[i][c] + f[i + 1][c - coins[i]];
                }
            }
        }
        return f[n][amount];
    }
};
// @lc code=end
