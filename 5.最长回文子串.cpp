/*
 * @lc app=leetcode.cn id=5 lang=cpp
 *
 * [5] 最长回文子串
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int maxL = 1;
        string ret = s.substr(0, 1);
        if (s.size() == 1) {
            return ret;
        }
        // 查找 "aba" 的形式
        for (int mid = 1; mid < n - 1; mid++) {
            int l = mid - 1;
            int r = mid + 1;
            int length = 1;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
                length += 2;
            }
            if (length > maxL) {
                maxL = length;
                ret = s.substr(l + 1, length);
            }
        }
        // 查找 "abba" 的形式
        for (int mid = 1; mid < n; mid++) {
            int l = mid - 1;
            int r = mid;
            int length = 0;
            while (l >= 0 && r < n) {
                if (s[l] != s[r]) {
                    break;
                }
                l--;
                r++;
                length += 2;
            }
            if (length > maxL) {
                maxL = length;
                ret = s.substr(l + 1, length);
            }
        }
        return ret;
    }
};
// @lc code=end
