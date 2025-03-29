/*
 * @lc app=leetcode.cn id=301 lang=cpp
 *
 * [301] 删除无效的括号
 */
#include <stack>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> ansSet;
        int lremove = 0, rremove = 0;

        // Step 1: 计算需要删除的左右括号数量
        for (char c : s) {
            if (c == '(') {
                lremove++;
            } else if (c == ')') {
                if (lremove > 0)
                    lremove--;
                else
                    rremove++;
            }
        }

        string path;
        // Step 2: 回溯生成所有有效组合
        dfs(s, 0, lremove, rremove, 0, path, ansSet);
        return vector<string>(ansSet.begin(), ansSet.end());
    }

private:
    void dfs(string &s,
             int index,
             int lremove,
             int rremove,
             int open,
             string &path,
             unordered_set<string> &ansSet) {

        // 剪枝：剩余字符不足以完成删除
        if (s.size() - index < lremove + rremove) {
            return;
        }

        // 终止条件
        if (index == s.size()) {
            if (lremove == 0 && rremove == 0 && open == 0) {
                ansSet.insert(path);
            }
            return;
        }

        char c = s[index];

        // 情况1: 删除当前字符
        if (c == '(' && lremove > 0) {
            dfs(s, index + 1, lremove - 1, rremove, open, path,
                ansSet);
        } else if (c == ')' && rremove > 0) {
            dfs(s, index + 1, lremove, rremove - 1, open, path,
                ansSet);
        }

        // 情况2: 保留当前字符
        path.push_back(c);
        if (c == '(') {
            dfs(s, index + 1, lremove, rremove, open + 1, path,
                ansSet);
        } else if (c == ')') {
            if (open > 0) { // 确保闭合有效
                dfs(s, index + 1, lremove, rremove, open - 1, path,
                    ansSet);
            }
        } else {
            dfs(s, index + 1, lremove, rremove, open, path, ansSet);
        }
        path.pop_back();
    }
};
// @lc code=end
