/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.length(), m = t.length(), left = 0, length = n + 1,
            start = 0, less = 0;
        unordered_map<char, int> cnt;
        for (int i = 0; i < m; i++) {
            if (cnt[t[i]] == 0) {
                less++;
            }
            cnt[t[i]]++;
        }

        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;
            if (cnt[s[right]] == 0) {
                less--;
            }
            while (less == 0) {
                if (right - left + 1 < length) {
                    length = right - left + 1;
                    start = left;
                }
                if (cnt[s[left]] == 0) {
                    less++;
                }
                cnt[s[left]]++;
                left++;
            }
        }
        if (length > n) {
            return "";
        } else {
            return s.substr(start, length);
        }
    }
};
// @lc code=end
