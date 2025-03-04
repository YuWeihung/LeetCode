/*
 * @lc app=leetcode.cn id=2563 lang=cpp
 *
 * [2563] 统计公平数对的数目
 */
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int lower_bound(vector<int> &nums, int length, int target) {
        int left = 0, right = length - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    long long
        countFairPairs(vector<int> &nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = nums[i];
            int start = lower_bound(nums, i, lower - x);
            int end = lower_bound(nums, i, upper - x + 1) - 1;
            int length = end - start + 1;
            ans += length;
        }
        return ans;
    }
};
// @lc code=end
