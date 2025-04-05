/*
 * @lc app=leetcode.cn id=2266 lang=cpp
 *
 * [2266] 统计打字方案数
 */
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
const int MOD = 1'000'000'007;
const int MX = 100'001;

long long f[MX], g[MX];

class Solution {
public:
    int countTexts(string s) {
        long long ans = 1;
        int cnt = 0;
        f[0] = g[0] = 1;
        f[1] = g[1] = 1;
        f[2] = g[2] = 2;
        f[3] = g[3] = 4;
        for (int i = 4; i <= s.length(); ++i) {
            f[i] = (f[i - 1] + f[i - 2] + f[i - 3]) % MOD;
            g[i] = (g[i - 1] + g[i - 2] + g[i - 3] + g[i - 4]) % MOD;
        }
        for (int i = 0; i < s.length(); i++) {
            char c = s[i];
            cnt++;
            if (i == s.length() - 1 || c != s[i + 1]) {
                ans = ans * (c != '7' && c != '9' ? f[cnt] : g[cnt]) %
                      MOD;
                cnt = 0;
            }
        }
        return ans;
    }
};
// @lc code=end
