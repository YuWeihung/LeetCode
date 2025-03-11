/*
 * @lc app=leetcode.cn id=2439 lang=cpp
 *
 * [2439] 最小化数组中的最大值
 */
#include <vector>

using namespace std;

// check() true 满足 right = mid - 1 false left = mid + 1
// left - 1 不满足 right + 1 满足

// @lc code=start
class Solution {
public:
    bool check(vector<int> &nums, long long ans) {
        long long extra = 0;
        for (int i = nums.size() - 1; i > 0; i--) {
            if (nums[i] + extra <= ans) {
                extra = 0;
            } else {
                extra = nums[i] + extra - ans;
            }
        }
        if (nums[0] + extra <= ans) {
            return true;
        } else {
            return false;
        }
    }

    int minimizeArrayValue(vector<int> &nums) {
        int left = 0,
            right = *max_element(nums.begin(), nums.end()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(nums, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
