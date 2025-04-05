/*
 * @lc app=leetcode.cn id=2466 lang=cpp
 *
 * [2466] 统计构造好字符串的方案数
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    const int MOD = 1e9 + 7;

    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> f(high + 1);
        int ans = 0;
        f[0] = 1;
        for (int i = 1; i <= high; i++) {
            if (i >= zero) {
                f[i] = f[i - zero] % MOD;
            }
            if (i >= one) {
                f[i] = (f[i] + f[i - one]) % MOD;
            }
            if (i >= low) {
                ans = (ans + f[i]) % MOD;
            }
        }
        return ans;
    }
};
// @lc code=end
