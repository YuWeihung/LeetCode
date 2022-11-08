/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 回溯法
    void backTrack(vector<vector<int>> &ret,
                   vector<int> &cur,
                   const vector<int> &candidates,
                   int index,
                   int sum,
                   int target) {
        if (sum == target) {
            ret.emplace_back(cur);
            return;
        }
        // 剪枝
        else if (sum > target) {
            return;
        } else if (index == candidates.size()) {
            return;
        } else {
            // 选择当前下标或直接跳过
            // 选择
            cur.emplace_back(candidates[index]);
            sum += candidates[index];
            backTrack(ret, cur, candidates, index, sum, target);
            sum -= candidates[index];
            cur.pop_back();
            // 跳过
            backTrack(ret, cur, candidates, index + 1, sum, target);
        }
    }

    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        vector<vector<int>> ret;
        vector<int> cur;
        int sum = 0;
        int index = 0;
        backTrack(ret, cur, candidates, index, sum, target);
        return ret;
    }
};
// @lc code=end
