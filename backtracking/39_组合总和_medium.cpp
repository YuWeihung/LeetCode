/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int i,
             int left,
             vector<int> &candidates,
             vector<int> &path) {
        if (left == 0) {
            ans.emplace_back(path);
            return;
        }
        if (i == candidates.size() || left < candidates[i]) {
            return;
        }
        dfs(i + 1, left, candidates, path);
        path.push_back(candidates[i]);
        left -= candidates[i];
        dfs(i, left, candidates, path);
        path.pop_back();
    }
    vector<vector<int>> combinationSum(vector<int> &candidates,
                                       int target) {
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates, path);
        return ans;
    }
};
// @lc code=end
