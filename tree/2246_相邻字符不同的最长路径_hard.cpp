/*
 * @lc app=leetcode.cn id=2246 lang=cpp
 *
 * [2246] 相邻字符不同的最长路径
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int longestPath(vector<int> &parent, string s) {
        int n = parent.size();
        vector<vector<int>> g(n);
        for (int i = 1; i < n; i++) {
            g[parent[i]].push_back(i);
        }
        int ans = 0;
        auto dfs = [&](auto &&dfs, int x) -> int {
            int max_len = 0;
            for (int y : g[x]) {
                int len = dfs(dfs, y) + 1;
                if (s[y] != s[x]) {
                    ans = max(ans, max_len + len);
                    max_len = max(max_len, len);
                }
            }
            return max_len;
        };
        dfs(dfs, 0);
        return ans + 1;
    }
};
// @lc code=end
