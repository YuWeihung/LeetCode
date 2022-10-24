/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 */
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    /*
     * 原地对比
     * isalnum() 判断是否为字母或数字
     * tolower() 转换为小写字母
     */
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            if (left < right) {
                if (tolower(s[left]) != tolower(s[right])) {
                    return false;
                }
                left++;
                right--;
            }
        }
        return true;
    }
};
// @lc code=end
