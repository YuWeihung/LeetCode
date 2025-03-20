/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> MAPPING = {"",    "",    "abc",  "def", "ghi",
                              "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> ans;
    void dfs(int i, string &digits, int n, string &path) {
        if (i == n) {
            ans.push_back(path);
            return;
        }
        for (char c : MAPPING[digits[i] - '0']) {
            path[i] = c;
            dfs(i + 1, digits, n, path);
        }
    }

    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        if (n == 0) {
            return {};
        }
        string path(n, 0);
        dfs(0, digits, n, path);
        return ans;
    }
};
// @lc code=end
