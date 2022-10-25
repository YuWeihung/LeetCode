/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * 摩尔投票法求众数
     * 思想是候选人遇到相同的就票数 +1 遇到不同的票数 -1
     * 如果票数为 0 就更换候选人
     * 由于众数出现次数超过 n/2 故最后它作为候选人的票数一定为正
     */
    int majorityElement(vector<int> &nums) {
        int ret = 0;
        int count = 0;
        for (auto x : nums) {
            if (count == 0) {
                ret = x;
                count = 1;
            } else {
                if (x == ret) {
                    count++;
                } else {
                    count--;
                }
            }
        }
        return ret;
    }
};
// @lc code=end
