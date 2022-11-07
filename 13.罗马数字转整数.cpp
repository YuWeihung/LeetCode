/*
 * @lc app=leetcode.cn id=13 lang=cpp
 *
 * [13] 罗马数字转整数
 */
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> values{
            {'I',    1},
            {'V',    5},
            {'X',   10},
            {'L',   50},
            {'C',  100},
            {'D',  500},
            {'M', 1000}
        };
        int ans = 0;
        for (int i = 0; i < s.length(); i++) {
            int value = values[s[i]];
            // 如果左边比右边的小则减去该值，反之则加上该值
            if (i < s.length() - 1 && value < values[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};
// @lc code=end
