/*
 * @lc app=leetcode.cn id=448 lang=cpp
 *
 * [448] 找到所有数组中消失的数字
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 遍历数组，遇到 x 就将 nums[x - 1] + n
     * 最后 nums[i] <= n 即 i + 1 没有出现过
     */
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            int x = (nums[i] - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.emplace_back(i + 1);
            }
        }
        return ret;
    }
};
// @lc code=end
