/*
 * @lc app=leetcode.cn id=2915 lang=cpp
 *
 * [2915] 和为目标值的最长子序列的长度
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubsequence(vector<int> &nums, int target) {
        int n = nums.size();
        vector<vector<int>> f(n + 1,
                              vector<int>(target + 1, INT_MIN));
        f[0][0] = 0;
        for (int i = 0; i < n; i++) {
            for (int c = 0; c <= target; c++) {
                if (c < nums[i]) {
                    f[i + 1][c] = f[i][c];
                } else {
                    f[i + 1][c] = max(f[i][c], f[i][c - nums[i]] + 1);
                }
            }
        }
        return f[n][target] > 0 ? f[n][target] : -1;
    }
};
// @lc code=end
