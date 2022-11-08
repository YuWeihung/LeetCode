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
    // 回溯法
    // 记录左右括号的数量,添加括号后要撤销
    void backTrack(vector<string> &ret, string &cur, int n, int l, int r) {
        if (r == n) {
            ret.emplace_back(cur);
        } else if (l == n) {
            cur.push_back(')');
            backTrack(ret, cur, n, l, r + 1);
            cur.pop_back();
        } else if (l == r) {
            cur.push_back('(');
            backTrack(ret, cur, n, l + 1, r);
            cur.pop_back();
        } else if (l > r) {
            cur.push_back('(');
            backTrack(ret, cur, n, l + 1, r);
            cur.pop_back();
            cur.push_back(')');
            backTrack(ret, cur, n, l, r + 1);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ret;
        string cur;
        int l = 0;
        int r = 0;
        backTrack(ret, cur, n, l, r);
        return ret;
    }
};
// @lc code=end
