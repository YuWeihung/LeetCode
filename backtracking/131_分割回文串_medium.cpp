/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isPalindrome(string &s, int left, int right) {
        while (left < right) {
            if (s[left++] != s[right--]) {
                return false;
            }
        }
        return true;
    }

    // 考虑 i 后面的逗号怎么选
    // start 表示当前这段回文子串的开始位置
    void dfs(int i,
             int start,
             int n,
             string &s,
             vector<string> &path,
             vector<vector<string>> &ans) {
        if (i == n) { // s 分割完毕
            ans.emplace_back(path);
            return;
        }

        // 不选 i 和 i+1 之间的逗号（i=n-1 时一定要选）
        if (i < n - 1) {
            // 考虑 i+1 后面的逗号怎么选
            dfs(i + 1, start, n, s, path, ans);
        }

        // 选 i 和 i+1 之间的逗号（把 s[i]
        // 作为子串的最后一个字符）
        if (isPalindrome(s, start, i)) {
            path.push_back(s.substr(start, i - start + 1));
            // 考虑 i+1 后面的逗号怎么选
            // start=i+1 表示下一个子串从 i+1 开始
            dfs(i + 1, i + 1, n, s, path, ans);
            path.pop_back(); // 恢复现场
        }
    }

    vector<vector<string>> partition(string s) {
        int n = s.length();
        vector<string> path;
        vector<vector<string>> ans;
        dfs(0, 0, n, s, path, ans);
        return ans;
    }
};
// @lc code=end
