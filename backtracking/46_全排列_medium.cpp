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
    vector<vector<int>> ans;
    void dfs(int i,
             int n,
             vector<int> &nums,
             vector<int> &path,
             vector<int> &on_path) {
        if (i == n) {
            ans.emplace_back(path);
            return;
        }
        for (int j = 0; j < n; j++) {
            if (!on_path[j]) {
                path.push_back(nums[j]);
                on_path[j] = true;
                dfs(i + 1, n, nums, path, on_path);
                path.pop_back();
                on_path[j] = false;
            }
        }
    }
    vector<vector<int>> permute(vector<int> &nums) {
        int n = nums.size();
        vector<int> path;
        vector<int> on_path(n);
        dfs(0, n, nums, path, on_path);
        return ans;
    }
};
// @lc code=end
