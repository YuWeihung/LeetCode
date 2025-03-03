/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        int ans = 0;
        int left = 0, right = n - 1;
        int leftMax = 0, rightMax = 0;
        while (left <= right) {
            leftMax = max(height[left], leftMax);
            rightMax = max(height[right], rightMax);
            if (leftMax < rightMax) {
                ans += leftMax - height[left];
                left++;
            } else {
                ans += rightMax - height[right];
                right--;
            }
        }
        return ans;
    }
};
// @lc code=end
