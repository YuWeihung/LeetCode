/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        // 负数不可能为回文数
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }
        int num = 0;
        // 只需翻转后一半即可
        while (x > num) {
            num = num * 10 + x % 10;
            x /= 10;
        }
        // x 为偶数应相等，x 为奇数时 num 去除最后一位（即中间位）与 x 相等
        return (x == num || x == num / 10);
    }
};
// @lc code=end
