/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            // 有序部分为后半段
            if (nums[mid] < nums[right]) {
                // 先在后半段判断
                if (nums[mid] < target && nums[right] >= target) {
                    left = mid + 1;
                }
                // 后半段没有去前半段继续二分
                else {
                    right = mid - 1;
                }
            }
            // 有序部分为前半段
            else {
                // 先在前半段判断
                if (nums[mid] > target && nums[left] <= target) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
        }
        // 最后区间只剩一个元素 left == right
        if (nums[left] == target) {
            return left;
        } else {
            return -1;
        }
    }
};
// @lc code=end
