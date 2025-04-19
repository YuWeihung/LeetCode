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
    long long
        countFairPairs(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            auto r = upper_bound(nums.begin(), nums.begin() + i,
                                 upper - nums[i]);
            auto l = lower_bound(nums.begin(), nums.begin() + i,
                                 lower - nums[i]);
            ans += r - l;
        }
        return ans;
    }
};
// @lc code=end
