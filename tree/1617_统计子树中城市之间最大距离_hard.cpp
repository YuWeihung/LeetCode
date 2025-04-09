/*
 * @lc app=leetcode.cn id=1617 lang=cpp
 *
 * [1617] 统计子树中城市之间最大距离
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int>
        countSubgraphsForEachDiameter(int n,
                                      vector<vector<int>> &edges) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0] - 1;
            int y = e[1] - 1;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> ans(n - 1), in_set(n), vis(n);
        int diameter = 0;

        auto dfs = [&](auto &&dfs, int x) -> int {
            vis[x] = true;
            int max_len = 0;
            for (int y : g[x]) {
                if (!vis[y] && in_set[y]) {
                    int ml = dfs(dfs, y) + 1;
                    diameter = max(diameter, max_len + ml);
                    max_len = max(max_len, ml);
                }
            }
            return max_len;
        };
        auto f = [&](auto &&f, int i) {
            if (i == n) {
                for (int v = 0; v < n; v++) {
                    if (in_set[v]) {
                        fill(vis.begin(), vis.end(), 0);
                        diameter = 0;
                        dfs(dfs, v);
                        break;
                    }
                }
                if (diameter && vis == in_set) {
                    ans[diameter - 1]++;
                }
                return;
            }
            f(f, i + 1);

            in_set[i] = true;
            f(f, i + 1);
            in_set[i] = false;
        };
        f(f, 0);
        return ans;
    }
};
// @lc code=end
