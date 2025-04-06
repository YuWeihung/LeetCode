/*
 * @lc app=leetcode.cn id=3040 lang=cpp
 *
 * [3040] 相同分数的最大操作数目 II
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int helper(int start,
               int end,
               int target,
               int n,
               vector<int> &nums) {
        vector f(n + 1, vector<int>(n + 1));
        for (int i = end - 1; i >= start; i--) {
            for (int j = i + 1; j <= end; j++) {
                if (nums[i] + nums[i + 1] == target) {
                    f[i][j + 1] =
                        max(f[i][j + 1], f[i + 2][j + 1] + 1);
                }
                if (nums[j - 1] + nums[j] == target) {
                    f[i][j + 1] = max(f[i][j + 1], f[i][j - 1] + 1);
                }
                if (nums[i] + nums[j] == target) {
                    f[i][j + 1] = max(f[i][j + 1], f[i + 1][j] + 1);
                }
            }
        }
        return f[start][end + 1];
    }

    int maxOperations(vector<int> &nums) {
        int n = nums.size();
        int res1 = helper(2, n - 1, nums[0] + nums[1], n, nums);
        int res2 =
            helper(0, n - 3, nums[n - 2] + nums[n - 1], n, nums);
        int res3 = helper(1, n - 2, nums[0] + nums[n - 1], n, nums);
        return max({res1, res2, res3}) + 1;
    }
};
// @lc code=end
