/*
 * @lc app=leetcode.cn id=2824 lang=cpp
 *
 * [2824] 统计和小于目标的下标对数目
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        int ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            if (nums[i] + nums[i + 1] >= target) {
                break;
            }
            int j = n - 1;
            while (i < j) {
                if (nums[i] + nums[j] >= target) {
                    j--;
                } else {
                    ans += j - i;
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
