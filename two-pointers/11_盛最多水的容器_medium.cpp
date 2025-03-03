/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int> &height) {
        long long maxA = 0;
        int n = height.size();
        int i = 0, j = n - 1;
        while (i < j) {
            long long a = min(height[i], height[j]) * (j - i);
            maxA = max(maxA, a);
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return maxA;
    }
};
// @lc code=end
