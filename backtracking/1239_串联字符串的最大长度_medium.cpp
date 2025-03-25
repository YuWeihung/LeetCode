/*
 * @lc app=leetcode.cn id=1239 lang=cpp
 *
 * [1239] 串联字符串的最大长度
 */
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> masks;
    vector<int> length;
    int ans = 0;

    void dfs(int i, int len, int mask) {
        ans = max(ans, len);
        if (i >= masks.size()) {
            ans = max(ans, len);
            return;
        }
        for (int j = i; j < masks.size(); j++) {
            if ((mask & masks[j]) == 0) {
                dfs(j + 1, len + length[j], mask | masks[j]);
            }
        }
    }

    int maxLength(vector<string> &arr) {
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            int mask = 0;
            for (int j = 0; j < arr[i].size(); j++) {
                int a = 1 << (arr[i][j] - 'a');
                if (a & mask) {
                    flag = false;
                    break;
                } else {
                    mask = mask | a;
                }
            }
            if (flag == true) {
                masks.push_back(mask);
                length.push_back(arr[i].size());
            }
        }
        dfs(0, 0, 0);
        return ans;
    }
};
// @lc code=end
