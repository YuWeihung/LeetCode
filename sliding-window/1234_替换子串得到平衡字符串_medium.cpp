/*
 * @lc app=leetcode.cn id=1234 lang=cpp
 *
 * [1234] 替换子串得到平衡字符串
 */
#include <string>
#include <unordered_map>

using namespace std;
// 窗口外的各字符数都不超过 target
// @lc code=start
class Solution {
public:
    int balancedString(string s) {
        int n = s.length(), ans = n, left = 0, target = n / 4;
        unordered_map<char, int> cnt;
        for (int i = 0; i < n; i++) {
            cnt[s[i]]++;
        }
        if (cnt['Q'] == target && cnt['W'] == target &&
            cnt['E'] == target && cnt['R'] == target) {
            return 0;
        }
        for (int right = 0; right < n; right++) {
            cnt[s[right]]--;
            while (cnt['Q'] <= target && cnt['W'] <= target &&
                   cnt['E'] <= target && cnt['R'] <= target) {
                ans = min(ans, right - left + 1);
                cnt[s[left]]++;
                left++;
            }
        }
        return ans;
    }
};
// @lc code=end
