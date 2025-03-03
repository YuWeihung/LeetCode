/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums) {
        int n = nums.size(), ans = n + 1, sum = 0, left = 0;
        for (int right = 0; right < n; right++) { // 枚举子数组右端点
            sum += nums[right];
            while (sum >= target) { // 满足要求
                ans = min(ans, right - left + 1);
                sum -= nums[left]; // 左端点右移
                left++;
            }
        }
        return ans <= n ? ans : 0;
    }
};
// @lc code=end
