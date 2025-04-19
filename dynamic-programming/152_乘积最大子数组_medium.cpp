/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子数组
 */
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int> &nums) {
        int n = nums.size();
        vector<int> f_max(n), f_min(n);
        f_max[0] = f_min[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int x = nums[i];
            f_max[i] = max({f_max[i - 1] * x, f_min[i - 1] * x, x});
            f_min[i] = min({f_max[i - 1] * x, f_min[i - 1] * x, x});
        }
        return *max_element(f_max.begin(), f_max.end());
    }
};
// @lc code=end
