/*
 * @lc app=leetcode.cn id=1499 lang=cpp
 *
 * [1499] 满足不等式的最大值
 */
#include <climits>
#include <deque>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>> &points, int k) {
        int ans = INT_MIN;
        deque<pair<int, int>> q;
        for (auto &p : points) {
            int x = p[0], y = p[1];
            while (!q.empty() &&
                   q.front().first < x - k) // 队首超出范围
                q.pop_front();              // 弹它！
            if (!q.empty())
                ans =
                    max(ans,
                        x + y + q.front().second); // 加上最大的 yi-xi
            while (!q.empty() &&
                   q.back().second <= y - x) // 队尾不如新来的强
                q.pop_back();                // 弹它！
            q.emplace_back(x, y - x);
        }
        return ans;
    }
};
// @lc code=end
