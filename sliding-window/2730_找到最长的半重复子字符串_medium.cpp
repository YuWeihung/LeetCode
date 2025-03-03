/*
 * @lc app=leetcode.cn id=2730 lang=cpp
 *
 * [2730] 找到最长的半重复子字符串
 */
#include <string>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int longestSemiRepetitiveSubstring(string s) {
        int n = s.length(), ans = 1, left = 0;
        int count = 0;
        for (int right = 1; right < n; right++) {
            if (s[right] == s[right - 1]) {
                count++;
            }
            if (count > 1) {
                left++;
                while (s[left] != s[left - 1]) {
                    left++;
                }
                count--;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
