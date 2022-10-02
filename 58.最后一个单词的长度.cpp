/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 */

#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        // 反向遍历数组
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index--;
        }
        int length = 0;
        while (index >= 0 && s[index] != ' ') {
            index--;
            length++;
        }
        return length;
    }
};
// @lc code=end
