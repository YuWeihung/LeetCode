/*
 * @lc app=leetcode.cn id=784 lang=cpp
 *
 * [784] 字母大小写全排列
 */
#include <cctype>
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> ans;

    void dfs(int i, int n, string &s, string &path) {
        if (i == n) {
            ans.push_back(path);
            return;
        }
        // 不变大小写
        path.push_back(s[i]);
        dfs(i + 1, n, s, path);
        // 变大小写
        if (isalpha(s[i])) {
            if (isupper(s[i])) {
                path[i] = tolower(s[i]);
            } else {
                path[i] = toupper(s[i]);
            }
            dfs(i + 1, n, s, path);
        }
        path.pop_back();
    }
    vector<string> letterCasePermutation(string s) {
        int n = s.length();
        string path = "";
        dfs(0, n, s, path);
        return ans;
    }
};
// @lc code=end
