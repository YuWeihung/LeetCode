/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    // 滑动窗口，双指针
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        unordered_set<char> hashSet;
        int n = s.size();
        // 右指针
        int r = -1;
        for (int l = 0; l < n; l++) {
            if (l != 0) {
                // 左指针向右移动，去除左边的字符
                hashSet.erase(s[l - 1]);
            }
            while (r + 1 < n && hashSet.count(s[r + 1]) == 0) {
                // 不断移动右指针
                hashSet.emplace(s[r + 1]);
                r++;
            }
            // 更新结果
            if (hashSet.size() > ret) {
                ret = hashSet.size();
            }
        }
        return ret;
    }
};
// @lc code=end
