/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size();
        vector<int> cnt(n + 1);
        for (int i = 0; i < n; i++) {
            cnt[min(citations[i], n)]++;
        }
        int s = 0;
        for (int i = n;; i--) {
            s += cnt[i];
            if (s >= i) {
                return i;
            }
        }
    }
};
// @lc code=end
