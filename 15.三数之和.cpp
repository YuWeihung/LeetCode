/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 排序 + 双指针
    vector<vector<int>> threeSum(vector<int> &nums) {
        int n = nums.size();
        // n < 3 时不存在
        if (n < 3) {
            return {{}};
        }
        // 对数组进行排序
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        // 遍历数组，三个元素 nums[i] <= nums[l] <= nums[r]
        for (int i = 0; i < n; i++) {
            // nums[i] > 0 后面不可能有三个数相加等于 0，直接返回
            if (nums[i] > 0) {
                break;
            }
            // 重复元素跳过，避免重复解
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            // 双指针, l 从小到大，r 从大到小遍历
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                if (nums[i] + nums[l] + nums[r] == 0) {
                    // 二维数组 emplact_back() 的用法
                    ret.emplace_back(vector<int>{nums[i], nums[l], nums[r]});
                    // 判断左右指针是否和下一位相同，去除重复解
                    while (l < r && nums[l] == nums[l + 1]) {
                        l++;
                    }
                    while (l < r && nums[r] == nums[r - 1]) {
                        r--;
                    }
                    l++;
                    r--;
                }
                // 和大于 0，说明 nums[r] 太大，r 左移，反之 l 右移
                else if (nums[i] + nums[l] + nums[r] > 0) {
                    r--;
                } else {
                    l++;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
