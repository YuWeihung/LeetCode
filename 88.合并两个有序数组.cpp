/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 */

#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        int i = m - 1, j = n - 1;
        int cur = m + n - 1;
        // 从后往前遍历，这样就不需要额外的临时数组
        while (i >= 0 && j >= 0) {
            if (nums1[i] >= nums2[j]) {
                nums1[cur] = nums1[i];
                i--;
            } else {
                nums1[cur] = nums2[j];
                j--;
            }
            cur--;
        }
        while (i >= 0) {
            nums1[cur] = nums1[i];
            i--;
            cur--;
        }
        while (j >= 0) {
            nums1[cur] = nums2[j];
            j--;
            cur--;
        }
    }
};
// @lc code=end
