/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 */

// @lc code=start
class Solution {
public:
    int climbStairs(int n) {
        int f1 = 0;
        int f2 = 0;
        int ans = 1;
        // 斐波那契数列求值
        for (int i = 1; i <= n; i++) {
            f1 = f2;
            f2 = ans;
            ans = f1 + f2;
        }
        return ans;
    }
};
// @lc code=end
