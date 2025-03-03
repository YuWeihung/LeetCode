/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int ans = nums[0] + nums[1] + nums[2];
        int bias = abs(target - ans);
        int n = nums.size();
        for (int i = 0; i < n - 2; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int x = nums[i] + nums[i + 1] + nums[i + 2];
            if (x > target) {
                if (x - target < bias) {
                    bias = x - target;
                    ans = x;
                }
                break;
            }
            x = nums[i] + nums[n - 2] + nums[n - 1];
            if (x < target) {
                if (target - x < bias) {
                    bias = target - x;
                    ans = x;
                }
                continue;
            }

            int j = i + 1, k = n - 1;
            while (j < k) {
                int x = nums[i] + nums[j] + nums[k];

                if (x == target) {
                    return target;
                } else if (x > target) {
                    if (x - target < bias) {
                        bias = x - target;
                        ans = x;
                    }
                    k--;
                } else {
                    if (target - x < bias) {
                        bias = target - x;
                        ans = x;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
