/*
 * @lc app=leetcode.cn id=2529 lang=cpp
 *
 * [2529] 正整数和负整数的最大计数
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
    int maximumCount(vector<int> &nums) {
        int pos_start = lower_bound(nums, 1);
        int neg_end = lower_bound(nums, 0) - 1;
        int pos_num = nums.size() - pos_start;
        int neg_num = neg_end + 1;
        return max(pos_num, neg_num);
    }
};
// @lc code=end
