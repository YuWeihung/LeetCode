/*
 * @lc app=leetcode.cn id=1377 lang=cpp
 *
 * [1377] T 秒后青蛙的位置
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    double frogPosition(int n,
                        vector<vector<int>> &edges,
                        int t,
                        int target) {
        vector<vector<int>> g(n + 1);
        g[1] = {0};
        for (auto &e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        double ans = 0;
        auto dfs = [&](auto &&dfs, int x, int fa, int left_t,
                       long long prod) -> bool {
            if (x == target && (left_t == 0 || g[x].size() == 1)) {
                ans = 1.0 / prod;
                return true;
            }
            if (x == target || left_t == 0) {
                return false;
            }
            for (int y : g[x]) {
                if (y != fa && dfs(dfs, y, x, left_t - 1,
                                   prod * (g[x].size() - 1))) {
                    return true;
                }
            }
            return false;
        };

        dfs(dfs, 1, 0, t, 1);
        return ans;
    }
};
// @lc code=end
