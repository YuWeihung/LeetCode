/*
 * @lc app=leetcode.cn id=2958 lang=cpp
 *
 * [2958] 最多 K 个重复元素的最长子数组
 */
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int maxSubarrayLength(vector<int> &nums, int k) {
        int n = nums.size(), ans = 0, left = 0;
        unordered_map<int, int> cnt;
        for (int right = 0; right < n; right++) {
            cnt[nums[right]]++;
            while (cnt[nums[right]] > k) {
                cnt[nums[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
