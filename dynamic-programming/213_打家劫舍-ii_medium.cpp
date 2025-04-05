/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int helper(vector<int> &nums, int start, int end) {
        int n = nums.size();
        int f0 = 0, f1 = 0;
        for (int i = start; i < end; i++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
    int rob(vector<int> &nums) {
        int n = nums.size();

        // 偷 nums[0]，从 2 - (n - 1)
        // 不偷 nums[0]，从 1 - n
        return max(helper(nums, 2, n - 1) + nums[0],
                   helper(nums, 1, n));
    }
};
// @lc code=end
