/*
 * @lc app=leetcode.cn id=198 lang=cpp
 *
 * [198] 打家劫舍
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int rob(vector<int> &nums) {
        int f0 = 0, f1 = 0;
        for (int i = 0; i < nums.size(); i++) {
            int new_f = max(f1, f0 + nums[i]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
// @lc code=end
