/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 */
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start

class Solution {
public:
    // 回溯法，当题目出现所有组合时，应考虑回溯法
    void backTrack(vector<string> &combinations,
                   const unordered_map<char, string> &phoneMap,
                   const string &digits,
                   int index,
                   string &combination) {
        if (index == digits.size()) {
            // 处理完所有位，得到一个排列
            combinations.emplace_back(combination);
        } else {
            char digit = digits[index];
            const string &letters = phoneMap.at(digit);
            for (const char &letter : letters) {
                // 在排列末尾添加一个字母
                combination.push_back(letter);
                // 回溯处理后一位
                backTrack(combinations, phoneMap, digits, index + 1, combination);
                // 回退
                combination.pop_back();
            }
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) {
            return {};
        }
        vector<string> combinations;
        unordered_map<char, string> phoneMap{
            {'2',  "abc"},
            {'3',  "def"},
            {'4',  "ghi"},
            {'5',  "jkl"},
            {'6',  "mno"},
            {'7', "pqrs"},
            {'8',  "tuv"},
            {'9', "wxyz"}
        };
        string combination;
        backTrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }
};
// @lc code=end
