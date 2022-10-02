/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 */

#include <string>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.size() == 0) {
            return "";
        }
        int length = strs[0].size();
        int count = strs.size();
        // 暴力扫描
        for (int i = 0; i < length; i++) {
            char ch = strs[0][i];
            for (int j = 1; j < count; j++) {
                if (strs[j].size() <= i || strs[j][i] != ch) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end
