/*
 * @lc app=leetcode.cn id=494 lang=cpp
 *
 * [494] 目标和
 */
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        int s = accumulate(nums.begin(), nums.end(), 0) - abs(target);
        if (s < 0 || s % 2 == 1) {
            return 0;
        }
        int m = s / 2;
        int n = nums.size();
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= m; c++) {
                if (c < nums[i]) {
                    f[i + 1][c] = f[i][c];
                } else {
                    f[i + 1][c] = f[i][c] + f[i][c - nums[i]];
                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end
