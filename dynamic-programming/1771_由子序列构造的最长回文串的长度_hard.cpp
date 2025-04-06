/*
 * @lc app=leetcode.cn id=1771 lang=cpp
 *
 * [1771] 由子序列构造的最长回文串的长度
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPalindrome(string word1, string word2) {
        string s = word1 + word2;
        int n = s.length(), ans = 0;
        vector<vector<int>> f(n, vector<int>(n));
        for (int i = n - 1; i >= 0; i--) {
            f[i][i] = 1;
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    f[i][j] = f[i + 1][j - 1] + 2;
                    if (i < word1.length() && j >= word1.length()) {
                        ans = max(
                            ans,
                            f[i][j]); // f[i][j] 一定包含 s[i] 和 s[j]
                    }
                } else {
                    f[i][j] = max(f[i + 1][j], f[i][j - 1]);
                }
            }
        }
        return ans;
    }
};
// @lc code=end
