/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> ans;
    void dfs(int i, int open, int n, int m, string &path) {
        if (i == m) {
            ans.emplace_back(path);
            return;
        }
        if (open < n) {
            path.push_back('(');
            dfs(i + 1, open + 1, n, m, path);
            path.pop_back();
        }
        if (i - open < open) {
            path.push_back(')');
            dfs(i + 1, open, n, m, path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        int m = 2 * n;
        string path;
        dfs(0, 0, n, m, path);
        return ans;
    }
};
// @lc code=end
