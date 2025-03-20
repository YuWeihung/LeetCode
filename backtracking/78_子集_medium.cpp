/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(int i, int n, vector<int> &nums, vector<int> &path) {
        if (i == n) {
            ans.push_back(path);
            return;
        }
        dfs(i + 1, n, nums, path);
        path.push_back(nums[i]);
        dfs(i + 1, n, nums, path);
        path.pop_back();
    }

    vector<vector<int>> subsets(vector<int> &nums) {
        int n = nums.size();
        vector<int> path;
        dfs(0, n, nums, path);
        return ans;
    }
};
// @lc code=end
