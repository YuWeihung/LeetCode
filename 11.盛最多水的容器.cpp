/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 双指针
    // 每次移动值较小的那个指针
    int maxArea(vector<int> &height) {
        int ret = 0;
        int n = height.size();
        int l = 0, r = n - 1;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ret = max(ret, area);
            if (height[l] < height[r]) {
                l++;
            } else {
                r--;
            }
        }
        return ret;
    }
};
// @lc code=end
