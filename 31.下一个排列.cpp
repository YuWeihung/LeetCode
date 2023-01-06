/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 下一个排列算法：
     * 1. 从后向前 查找第一个 相邻升序 的元素对 (i,j)，满足 A[i] < A[j]。此时 [j,end) 必然是降序
     * 2. 在 [j,end) 从后向前 查找第一个满足 A[i] < A[k] 的 k。A[i]、A[k]
     * 分别就是上文所说的「小数」、「大数」
     * 3. 将 A[i] 与 A[k] 交换
     * 4. 可以断定这时 [j,end) 必然是降序，逆置 [j,end)，使其升序
     * 5. 如果在步骤 1 找不到符合的相邻元素对，说明当前 [begin,end) 为一个降序顺序，则直接跳到步骤 4
     */
    void nextPermutation(vector<int> &nums) {
        int length = nums.size();
        if (length <= 1) {
            return;
        }
        int i = length - 2;
        int j = length - 1;
        int k = length - 1;
        // 从后往前寻找第一个相邻升序对即 A[i] < A[j]
        while (i >= 0 && nums[i] >= nums[j]) {
            i--;
            j--;
        }
        // 如果不是最后一个排列
        if (i >= 0) {
            // 寻找 A[i] < A[k]
            while (nums[i] >= nums[k]) {
                k--;
            }
            // 交换 A[i] A[k]
            swap(nums[i], nums[k]);
        }
        // 将 [j, end] 反置
        reverse(next(nums.begin(), j), nums.end());
    }
};
// @lc code=end
