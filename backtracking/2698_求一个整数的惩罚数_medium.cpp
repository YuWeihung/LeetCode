/*
 * @lc app=leetcode.cn id=2698 lang=cpp
 *
 * [2698] 求一个整数的惩罚数
 */
#include <cctype>
#include <iostream>
#include <string>

using namespace std;

// @lc code=start
class Solution {
public:
    bool dfs(int i, string &s, int sum, int target) {
        if (i == s.size()) {
            return sum == target;
        }
        int cur = 0;
        for (int j = i; j < s.size(); j++) {
            cur = cur * 10 + s[j] - '0';
            if (sum + cur > target) {
                break;
            }
            if (dfs(j + 1, s, sum + cur, target)) {
                return true;
            }
        }
        return false;
    }

    int punishmentNumber(int n) {
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            string s = to_string(i * i);
            if (dfs(0, s, 0, i)) {
                ans += i * i;
            }
        }
        return ans;
    }
};
// @lc code=end
