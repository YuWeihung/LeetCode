/*
 * @lc app=leetcode.cn id=2646 lang=cpp
 *
 * [2646] 最小化旅行的价格总和
 */
#include <algorithm>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int minimumTotalPrice(int n,
                          vector<vector<int>> &edges,
                          vector<int> &price,
                          vector<vector<int>> &trips) {
        vector<vector<int>> g(n);
        for (auto &e : edges) {
            int x = e[0], y = e[1];
            g[x].push_back(y);
            g[y].push_back(x);
        }
        vector<int> cnt(n);
        for (auto &t : trips) {
            int end = t[1];
            auto dfs = [&](auto &&dfs, int x, int fa) -> bool {
                if (x == end) {
                    cnt[x]++;
                    return true;
                }
                for (int y : g[x]) {
                    if (y != fa && dfs(dfs, y, x)) {
                        cnt[x]++;
                        return true;
                    }
                }
                return false;
            };
            dfs(dfs, t[0], -1);
        }
        auto dfs = [&](auto &&dfs, int x, int fa) -> pair<int, int> {
            int not_halve = price[x] * cnt[x];
            int halve = not_halve / 2;
            for (int y : g[x]) {
                if (y != fa) {
                    auto [nh, h] = dfs(dfs, y, x);
                    not_halve += min(nh, h);
                    halve += nh;
                }
            }
            return {not_halve, halve};
        };
        auto [nh, h] = dfs(dfs, 0, -1);
        return min(nh, h);
    }
};
// @lc code=end
