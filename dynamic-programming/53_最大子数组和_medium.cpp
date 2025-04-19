/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        for (int i = 1; i < n; i++) {
            f[i] = max(f[i - 1], 0) + nums[i];
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end
