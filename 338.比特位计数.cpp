/*
 * @lc app=leetcode.cn id=338 lang=cpp
 *
 * [338] 比特位计数
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 1. 如果一个数是奇数，那么它 1 的个数比它前一个数多 1，即末尾的 1
     * 2. 如果一个数是偶数，那么它 1 的个数与它右移一位即除以二之后的数相同，
     *    即去掉了末尾的 0
     */
    vector<int> countBits(int n) {
        vector<int> ret(n + 1, 0);
        ret[0] = 0;
        for (int i = 1; i <= n; i++) {
            if (i % 2 == 1) {
                ret[i] = ret[i - 1] + 1;
            } else {
                ret[i] = ret[i / 2];
            }
        }
        return ret;
    }
};
// @lc code=end
