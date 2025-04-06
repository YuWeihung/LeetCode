/*
 * @lc app=leetcode.cn id=1626 lang=cpp
 *
 * [1626] 无矛盾的最佳球队
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages) {
        int n = scores.size();
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            a[i] = {scores[i], ages[i]};
        }
        sort(a.begin(), a.end());
        vector<int> f(n);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (a[j].second <= a[i].second) {
                    f[i] = max(f[i], f[j]);
                }
            }
            f[i] += a[i].first;
        }
        return *max_element(f.begin(), f.end());
    }
};
// @lc code=end
