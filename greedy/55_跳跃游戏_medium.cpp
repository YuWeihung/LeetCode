/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int> &nums) {
        int mx = 0, n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mx < i) {
                return false;
            }
            if (mx >= n - 1) {
                return true;
            }
            mx = max(mx, i + nums[i]);
        }
        return true;
    }
};
// @lc code=end
