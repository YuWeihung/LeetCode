/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 回溯法
    // flag[] 记录一个数是否被使用
    void backTrack(vector<vector<int>> &perms,
                   vector<int> &perm,
                   const vector<int> &nums,
                   int depth,
                   vector<int> &flag) {
        int n = nums.size();
        if (depth == n) {
            perms.emplace_back(perm);
        } else {
            for (int i = 0; i < n; i++) {
                // 如果一个数没被使用，标记为被使用，回溯
                if (flag[i] == 0) {
                    flag[i] = 1;
                    perm.emplace_back(nums[i]);
                    backTrack(perms, perm, nums, depth + 1, flag);
                    perm.pop_back();
                    flag[i] = 0;
                }
            }
        }
    }

    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<vector<int>> perms;
        vector<int> perm;
        vector<int> flag(n, 0);
        backTrack(perms, perm, nums, 0, flag);
        return perms;
    }
};
// @lc code=end
