/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    bool is_blue(vector<int> &nums, int target, int mid) {
        int end = nums.back();
        int x = nums[mid];
        if (x > end) {
            if (target > end && x >= target) {
                return true;
            } else {
                return false;
            }
        } else {
            if (target > end || x >= target) {
                return true;
            } else {
                return false;
            }
        }
    }

    int search(vector<int> &nums, int target) {
        int n = nums.size(), left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (is_blue(nums, target, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        if (left == n || nums[left] != target) {
            return -1;
        } else {
            return left;
        }
    }
};
// @lc code=end
