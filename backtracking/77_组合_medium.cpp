/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void dfs(int i,
             int n,
             int k,
             vector<int> &path,
             vector<vector<int>> &ans) {
        int d = k - path.size();
        if (d == 0) {
            ans.emplace_back(path);
            return;
        }
        if (i > d) {
            dfs(i - 1, n, k, path, ans);
        }
        path.push_back(i);
        dfs(i - 1, n, k, path, ans);
        path.pop_back();
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> ans;
        dfs(n, n, k, path, ans);
        return ans;
    }
};
// @lc code=end
