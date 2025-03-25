/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */
#include <cctype>
#include <string>
#include <vector>
using namespace std;

// @lc code=start

class Solution {
public:
    string num;
    int n;
    vector<vector<int>> list;
    bool isAdditiveNumber(string _num) {
        num = _num;
        n = _num.size();
        return dfs(0);
    }
    bool dfs(int u) {
        int m = list.size();
        if (u == n)
            return m >= 3;                   // 至少包含3个数
        int max = num[u] == '0' ? u + 1 : n; // 处理前导0
        vector<int> cur;
        for (int i = u; i < max; i++) { // 枚举[u,n - 1]
            cur.insert(cur.begin(), num[i] - '0');
            if (m < 2 || check(list[m - 2], list[m - 1], cur)) {
                list.push_back(cur);
                if (dfs(i + 1))
                    return true;
                list.pop_back();
            }
        }
        return false;
    }
    bool check(vector<int> &a, vector<int> &b, vector<int> &c) {
        vector<int> ans;
        int t = 0;
        for (int i = 0; i < a.size() || i < b.size(); i++) {
            if (i < a.size())
                t += a[i];
            if (i < b.size())
                t += b[i];
            ans.push_back(t % 10);
            t /= 10;
        }
        if (t)
            ans.push_back(1);               // 处理最高位的进位
        bool ok = (c.size() == ans.size()); // 检查长度
        for (int i = 0; i < c.size() && ok; i++) {
            if (c[i] != ans[i])
                ok = false; // 逐位检查
        }
        return ok;
    }
};

// @lc code=end
