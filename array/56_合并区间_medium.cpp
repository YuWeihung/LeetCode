/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>> &intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        for (auto cur : intervals) {
            if (!ans.empty() && cur[0] <= ans.back()[1]) {
                ans.back()[1] = max(ans.back()[1], cur[1]);
            } else {
                ans.emplace_back(cur);
            }
        }
        return ans;
    }
};
// @lc code=end
