/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 */
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 双指针
    int threeSumClosest(vector<int> &nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ret = nums[0] + nums[1] + nums[2];
        int diff = abs(target - ret);
        for (int i = 0; i < n; i++) {
            // 如果三倍的 nums[i - 1] 已经大于 target，后面比 target 大的更多
            if (i > 0 && nums[i - 1] * 3 > target) {
                return ret;
            }
            // 跳过重复的 nums[i]
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                // 相等直接返回
                if (sum == target) {
                    return sum;
                }
                if (abs(target - sum) < diff) {
                    diff = abs(target - sum);
                    ret = sum;
                }
                if (sum > target) {
                    // 去掉重复的 nums[r]
                    while (l < r && nums[r - 1] == nums[r]) {
                        r--;
                    }
                    r--;
                } else {
                    // 去掉重复的 nums[l]
                    while (l < r && nums[l + 1] == nums[l]) {
                        l++;
                    }
                    l++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
