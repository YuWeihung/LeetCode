/*
 * @lc app=leetcode.cn id=53 lang=cpp
 *
 * [53] 最大子数组和
 */
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int n = nums.size();
        int min_pre_sum = 0;
        int pre_sum = 0;
        int ans = INT_MIN;
        for (int i = 0; i < n; i++) {
            pre_sum += nums[i];
            ans = max(ans, pre_sum - min_pre_sum);
            min_pre_sum = min(min_pre_sum, pre_sum);
        }
        return ans;
    }
};
// @lc code=end
