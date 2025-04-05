/*
 * @lc app=leetcode.cn id=377 lang=cpp
 *
 * [377] 组合总和 Ⅳ
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int combinationSum4(vector<int> &nums, int target) {
        vector<unsigned> f(target + 1);
        f[0] = 1;
        for (int i = 1; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (nums[j] <= i) {
                    f[i] += f[i - nums[j]];
                }
            }
        }
        return f[target];
    }
};
// @lc code=end
