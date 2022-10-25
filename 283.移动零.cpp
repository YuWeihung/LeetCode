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
        // left 左边全非零，left 右边到 right 左边全为零
        // 每次将 left 处的零与 right 处非零交换，不改变非零数次序
        while (right < nums.size()) {
            if (nums[right] != 0) {
                swap(nums[left], nums[right]);
                left++;
            }
            right++;
        }
    }
};
// @lc code=end
