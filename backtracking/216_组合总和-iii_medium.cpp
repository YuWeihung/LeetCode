/*
 * @lc app=leetcode.cn id=216 lang=cpp
 *
 * [216] 组合总和 III
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int i, int t, int k, vector<int> &path) {
        int d = k - path.size();
        if (t < 0 || t > (i * 2 - d + 1) * d / 2) {
            return;
        }
        if (d == 0) {
            ans.emplace_back(path);
            return;
        }
        if (i > d) {
            dfs(i - 1, t, k, path);
        }
        path.push_back(i);
        dfs(i - 1, t - i, k, path);
        path.pop_back();
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> path;
        dfs(9, n, k, path);
        return ans;
    }
};
// @lc code=end
