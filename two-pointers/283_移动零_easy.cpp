/*
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int left = 0, right = 0;
        for (right = 0; right < nums.size(); ++right) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
        }
    }
};
// @lc code=end
