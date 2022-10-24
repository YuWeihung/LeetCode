/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 通过依次异或可以求得数组中仅出现一次的数字
    int singleNumber(vector<int> &nums) {
        int result = 0;
        for (int i : nums) {
            result ^= i;
        }
        return result;
    }
};
// @lc code=end
