/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        int j = 1;
        // 双指针遍历数组
        while (j < nums.size()) {
            if (nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};
// @lc code=end
