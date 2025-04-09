/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        auto quick_select = [&](auto &&quick_select, int l, int r,
                                int k) {
            if (l == r) {
                return nums[k];
            }
            int x = nums[l], i = l - 1, j = r + 1;
            while (i < j) {
                do
                    i++;
                while (nums[i] < x);
                do
                    j--;
                while (nums[j] > x);
                if (i < j) {
                    swap(nums[i], nums[j]);
                }
            }
            if (k <= j)
                return quick_select(quick_select, l, j, k);
            else
                return quick_select(quick_select, j + 1, r, k);
        };
        int n = nums.size();
        return quick_select(quick_select, 0, n - 1, n - k);
    }
};
// @lc code=end
