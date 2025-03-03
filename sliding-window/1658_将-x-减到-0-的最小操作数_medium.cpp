/*
 * @lc app=leetcode.cn id=1658 lang=cpp
 *
 * [1658] 将 x 减到 0 的最小操作数
 */
#include <numeric>
#include <vector>

using namespace std;
// 逆向思维, 求连续子序列, 和为 sum - x
// @lc code=start
class Solution {
public:
    int minOperations(vector<int> &nums, int x) {
        int n = nums.size(), left = 0, length = 0;
        int sum = accumulate(nums.begin(), nums.end(), 0);
        int target = sum - x;
        if (target < 0) {
            return -1;
        }
        if (target == 0) {
            return n;
        }
        sum = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum > target) {
                sum -= nums[left];
                left++;
            }
            if (sum == target) {
                length = max(length, right - left + 1);
            }
        }
        if (length == 0) {
            return -1;
        } else {
            return n - length;
        }
    }
};
// @lc code=end
