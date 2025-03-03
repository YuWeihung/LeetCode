/*
 * @lc app=leetcode.cn id=1004 lang=cpp
 *
 * [1004] 最大连续1的个数 III
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int longestOnes(vector<int> &nums, int k) {
        int cnt = 0, ans = 0, left = 0, n = nums.size();
        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                cnt++;
            }
            if (cnt > k) {
                while (nums[left] == 1) {
                    left++;
                }
                left++;
                cnt--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
