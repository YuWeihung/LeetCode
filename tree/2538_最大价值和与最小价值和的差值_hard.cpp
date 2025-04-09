/*
 * @lc app=leetcode.cn id=2538 lang=cpp
 *
 * [2538] 最大价值和与最小价值和的差值
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    long long maxOutput(int n,
                        vector<vector<int>> &edges,
                        vector<int> &price) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0];
            int y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }

        long long ans = 0;
        auto dfs = [&](auto &&dfs, int x,
                       int fa) -> pair<long long, long long> {
            long long p = price[x], max_s1 = p, max_s2 = 0;
            for (int y : g[x]) {
                if (y != fa) {
                    auto [s1, s2] = dfs(dfs, y, x);
                    ans = max(ans, max(max_s1 + s2, s1 + max_s2));
                    max_s1 = max(max_s1, s1 + p);
                    max_s2 = max(max_s2, s2 + p);
                }
            }
            return {max_s1, max_s2};
        };
        dfs(dfs, 0, -1);
        return ans;
    }
};
// @lc code=end
