/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int n = cost.size();
        int f0 = 0;
        int f1 = 0;
        for (int i = 2; i < n + 1; i++) {
            int new_f = min(f0 + cost[i - 2], f1 + cost[i - 1]);
            f0 = f1;
            f1 = new_f;
        }
        return f1;
    }
};
// @lc code=end
