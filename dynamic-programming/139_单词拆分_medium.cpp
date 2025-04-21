/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */
#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        int max_len = 0;
        for (auto &word : wordDict) {
            int len = word.size();
            max_len = max(max_len, len);
        }
        unordered_set<string> words(wordDict.begin(), wordDict.end());
        int n = s.size();

        vector<int> f(n + 1);
        f[0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = i - 1; j >= max(i - max_len, 0); j--) {
                if (f[j] && words.count(s.substr(j, i - j))) {
                    f[i] = 1;
                    break;
                }
            }
        }
        return f[n];
    }
};
// @lc code=end
