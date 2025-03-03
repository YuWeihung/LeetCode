/*
 * @lc app=leetcode.cn id=2302 lang=cpp
 *
 * [2302] 统计得分小于 K 的子数组数目
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int> &nums, long long k) {
        int n = nums.size(), left = 0, length = 0;
        long long sum = 0, point = 0, ans = 0;
        for (int right = 0; right < n; right++) {
            sum += nums[right];
            while (sum * (right - left + 1) >= k) {
                sum -= nums[left];
                left++;
            }
            ans += right - left + 1;
        }
        return ans;
    }
};
// @lc code=end
