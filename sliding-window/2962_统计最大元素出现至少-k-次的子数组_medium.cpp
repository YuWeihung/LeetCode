/*
 * @lc app=leetcode.cn id=2962 lang=cpp
 *
 * [2962] 统计最大元素出现至少 K 次的子数组
 */
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    long long countSubarrays(vector<int> &nums, int k) {
        auto maxIt = max_element(nums.begin(), nums.end());
        int maxn = *maxIt, left = 0, n = nums.size(), cnt = 0;
        long long ans = 0;
        for (int right = 0; right < n; right++) {
            if (nums[right] == maxn) {
                cnt++;
            }
            while (cnt == k) {
                if (nums[left] == maxn) {
                    cnt--;
                }
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end
