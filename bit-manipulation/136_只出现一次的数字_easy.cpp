/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int ret = 0;
        for (int i = 0; i < nums.size(); i++) {
            ret = ret ^ nums[i];
        }
        return ret;
    }
};
// @lc code=end
