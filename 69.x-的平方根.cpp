/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */
#include <cmath>
using namespace std;

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x == 0) {
            return 0;
        }

        // 牛顿迭代法求值
        const double C = x;
        double x0 = x;
        while (true) {
            double xi = 0.5 * (x0 + C / x0);
            // 对于浮点数用 fabs 取绝对值
            if (fabs(xi - x0) < 1e-7) {
                break;
            }
            x0 = xi;
        }
        return int(x0);
    }
};
// @lc code=end
