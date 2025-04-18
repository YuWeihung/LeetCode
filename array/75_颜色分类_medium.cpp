/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int> &nums) {
        int p0 = 0, i = 0, p2 = nums.size() - 1;
        while (i <= p2) {
            if (nums[i] == 0) {
                swap(nums[i], nums[p0]);
                p0++;
                i++;
            } else if (nums[i] == 2) {
                swap(nums[i], nums[p2]);
                p2--;
            } else {
                i++;
            }
        }
    }
};
// @lc code=end
