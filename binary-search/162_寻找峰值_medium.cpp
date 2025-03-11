/*
 * @lc app=leetcode.cn id=162 lang=cpp
 *
 * [162] 寻找峰值
 */
#include <vector>

using namespace std;

//

// @lc code=start
class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int n = nums.size(), left = 0, right = n - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] > nums[mid + 1]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
