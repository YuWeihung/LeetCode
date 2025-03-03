/*
 * @lc app=leetcode.cn id=611 lang=cpp
 *
 * [611] 有效三角形的个数
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int triangleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = nums.size();
        for (int k = n - 1; k > 1; k--) {
            if (nums[k - 2] + nums[k - 1] <= nums[k]) {
                continue;
            }
            if (nums[0] + nums[1] > nums[k]) {
                ans += (k + 1) * k * (k - 1) / 6;
                break;
            }
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
