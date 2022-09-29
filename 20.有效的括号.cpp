/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <stack>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        // 长度为奇数必无效
        if (n % 2 == 1) {
            return false;
        }
        stack<char> stk;
        unordered_map<char, char> pairs = {{')', '('}, {']', '['}, {'}', '{'}};
        for (char ch : s) {
            // 如果是右括号，看是否与栈顶左括号匹配，匹配则出栈；如果是左括号，则入栈
            if (pairs.count(ch)) {
                if (stk.empty() || stk.top() != pairs[ch]) {
                    return false;
                } else {
                    stk.pop();
                }
            } else {
                stk.push(ch);
            }
        }
        // 如果最终栈清空了说明有效
        return stk.empty();
    }
};
// @lc code=end
