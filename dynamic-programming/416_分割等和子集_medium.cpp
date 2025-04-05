/*
 * @lc app=leetcode.cn id=416 lang=cpp
 *
 * [416] 分割等和子集
 */
#include <numeric>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int> &nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2 == 1) {
            return false;
        }
        int m = s / 2;
        vector<vector<int>> f(n + 1, vector<int>(m + 1));
        f[0][0] = 1;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= m; c++) {
                if (c < nums[i]) {
                    f[i + 1][c] = f[i][c];
                } else {
                    f[i + 1][c] = f[i][c] || f[i][c - nums[i]];
                }
            }
        }
        return f[n][m];
    }
};
// @lc code=end
