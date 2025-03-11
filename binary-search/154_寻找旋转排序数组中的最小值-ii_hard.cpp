/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int findMin(vector<int> &nums) {
        int left = 0, n = nums.size(), right = n - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int x = nums[mid];
            if (x > nums[right + 1]) {
                left = mid + 1;
            } else if (x < nums[right + 1]) {
                right = mid - 1;
            } else {
                right--;
            }
        }
        return nums[left];
    }
};
// @lc code=end
