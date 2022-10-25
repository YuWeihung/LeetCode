/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 位运算
     * s 的每一位代表该位 x 与 y 是否相同
     * s & 1 得到 s 的最低位
     * s >> 1 使 s 的次低位成为最低位
     */
    int hammingDistance(int x, int y) {
        int ret = 0;
        int s = x ^ y;
        while (s != 0) {
            ret += s & 1;
            s >>= 1;
        }
        return ret;
    }
};
// @lc code=end
