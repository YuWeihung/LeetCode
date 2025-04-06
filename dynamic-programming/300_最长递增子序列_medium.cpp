/*
 * @lc app=leetcode.cn id=300 lang=cpp
 *
 * [300] 最长递增子序列
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLIS(vector<int> &nums) {
        int n = nums.size();
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i]++;
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end
