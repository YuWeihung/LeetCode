/*
 * @lc app=leetcode.cn id=713 lang=cpp
 *
 * [713] 乘积小于 K 的子数组
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k <= 1) {
            return 0;
        }
        int n = nums.size(), product = 1, left = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            product *= nums[right];
            while (product >= k) {
                product /= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end
