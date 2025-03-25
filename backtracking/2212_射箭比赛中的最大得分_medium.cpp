/*
 * @lc app=leetcode.cn id=2212 lang=cpp
 *
 * [2212] 射箭比赛中的最大得分
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int max_point = 0;
    vector<int> ans;
    void dfs(int i,
             int used,
             int points,
             vector<int> &bobArrows,
             int numArrows,
             vector<int> &aliceArrows) {
        if (i == 12) {
            int before = bobArrows[0];
            bobArrows[0] += numArrows - used;
            if (points > max_point) {
                max_point = points;
                ans = bobArrows;
            }
            bobArrows[0] = before;
            return;
        }
        // 不得第i分
        dfs(i + 1, used, points, bobArrows, numArrows, aliceArrows);
        // 得第i分
        int need = aliceArrows[i] + 1;
        if (used + need <= numArrows) {
            bobArrows[i] = need;
            dfs(i + 1, used + need, points + i, bobArrows, numArrows,
                aliceArrows);
            bobArrows[i] = 0;
        }
    }

    vector<int> maximumBobPoints(int numArrows,
                                 vector<int> &aliceArrows) {
        vector<int> bobArrows(12, 0);
        dfs(0, 0, 0, bobArrows, numArrows, aliceArrows);
        return ans;
    }
};
// @lc code=end
