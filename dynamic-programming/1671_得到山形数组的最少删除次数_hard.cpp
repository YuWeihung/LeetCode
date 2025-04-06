/*
 * @lc app=leetcode.cn id=1671 lang=cpp
 *
 * [1671] 得到山形数组的最少删除次数
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumMountainRemovals(vector<int> &nums) {
        int n = nums.size();
        vector<int> dp_inc(n, 1); // 递增子序列长度（以i结尾）
        vector<int> dp_dec(n, 1); // 递减子序列长度（以i开头）

        // 计算递增子序列：从左到右
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i] && dp_inc[j] + 1 > dp_inc[i]) {
                    dp_inc[i] = dp_inc[j] + 1;
                }
            }
        }

        // 计算递减子序列：从右到左
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                if (nums[j] < nums[i] && dp_dec[j] + 1 > dp_dec[i]) {
                    dp_dec[i] = dp_dec[j] + 1;
                }
            }
        }

        // 寻找最长山峰子序列
        int max_len = 0;
        for (int i = 0; i < n; ++i) {
            if (dp_inc[i] > 1 &&
                dp_dec[i] > 1) { // 左右两侧必须都有元素
                max_len = max(max_len, dp_inc[i] + dp_dec[i] - 1);
            }
        }

        return n - max_len;
    }
};
// @lc code=end
