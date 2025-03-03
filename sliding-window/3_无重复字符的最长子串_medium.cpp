/*
 * @lc app=leetcode.cn id=3 lang=cpp
 *
 * [3] 无重复字符的最长子串
 */
#include <string>
#include <unordered_map>

using namespace std;
// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0, n = s.length(), left = 0;
        unordered_map<char, int> cnt;
        for (int right = 0; right < n; right++) {
            char ch = s[right];
            cnt[ch]++;
            while (cnt[ch] > 1) {
                cnt[s[left]]--;
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
