/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    // minType 为 true 查找最小下标，为 false 查找最大下标
    int binarySearch(vector<int> &nums, int target, bool minType) {
        int left = 0;
        int ret = -1;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                ret = mid;
                if (minType) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ret;
    }

    vector<int> searchRange(vector<int> &nums, int target) {
        int left = binarySearch(nums, target, true);
        int right = binarySearch(nums, target, false);
        return {left, right};
    }
};
// @lc code=end
