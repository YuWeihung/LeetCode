/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int jump(vector<int> &nums) {
        int n = nums.size();
        int ans = 0;
        int cur_right = 0;
        int next_right = 0;
        for (int i = 0; i < n - 1; i++) {
            next_right = max(next_right, i + nums[i]);
            if (i == cur_right) {
                cur_right = next_right;
                ans++;
            }
        }
        return ans;
    }
};
// @lc code=end
