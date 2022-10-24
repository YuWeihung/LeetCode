/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 递推公式
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 0);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            // long long 防止溢出
            row[i] = 1LL * row[i - 1] * (rowIndex - i + 1) / i;
        }
        return row;
    }
};
// @lc code=end
