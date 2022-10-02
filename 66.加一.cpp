/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        for (int i = digits.size() - 1; i >= 0; i--) {
            digits[i]++;
            digits[i] = digits[i] % 10;
            // 余数不为 0 表示没有进位，循环结束直接返回
            if (digits[i] != 0) {
                return digits;
            }
        }
        // 没有返回说明每一位都是进位，长度加 1，首项为 1，其余为 0
        vector<int> ans(digits.size() + 1, 0);
        ans[0] = 1;
        return ans;
    }
};
// @lc code=end
