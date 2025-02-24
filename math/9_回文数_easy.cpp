/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) {
            return false;
        }
        int y = x;
        long z = 0;
        while (y > 0) {
            int t = y % 10;
            y = y / 10;
            z = z * 10 + t;
        }
        return z == x;
    }
};
// @lc code=end
