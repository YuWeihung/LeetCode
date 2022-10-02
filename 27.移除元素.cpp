/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int> &nums, int val) {
        if (nums.size() == 0) {
            return 0;
        }
        int i = 0;
        // 双指针问题
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] != val) {
                nums[i] = nums[j];
                i++;
            }
        }
        return i;
    }
};
// @lc code=end
