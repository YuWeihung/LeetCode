/*
 * @lc app=leetcode.cn id=2826 lang=cpp
 *
 * [2826] 将三个组排序
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumOperations(vector<int> &nums) {
        int n = nums.size();
        vector f(n + 1, vector<int>(4));
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            for (int j = 1; j < 4; j++) {
                if (j < x) {
                    f[i + 1][j] = f[i][j];
                } else {
                    f[i + 1][j] = max(f[i][j], f[i][x] + 1);
                }
            }
        }
        return n - f[n][3];
    }
};
// @lc code=end
