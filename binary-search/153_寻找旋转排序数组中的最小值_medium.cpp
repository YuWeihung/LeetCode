/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */
#include <iostream>
#include <vector>
using namespace std;

// nums[mid] < nums[n - 1] 最小值或最小值右侧 蓝色
// > 最小值左侧 红色

// @lc code=start
class Solution {
public:
    int findMin(vector<int> &nums) {
        int n = nums.size(), left = 0, right = n - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < nums[n - 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return nums[left];
    }
};
// @lc code=end
