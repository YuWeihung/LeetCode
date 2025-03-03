/*
 * @lc app=leetcode.cn id=2779 lang=cpp
 *
 * [2779] 数组的最大美丽值
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 1, left = 0;
        for (int right = 0; right < n; right++) {
            while (nums[right] - nums[left] > 2 * k) {
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
