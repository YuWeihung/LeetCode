/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        result.emplace_back(vector<int>({1}));
        if (numRows == 1) {
            return result;
        }
        for (int i = 1; i < numRows; i++) {
            auto last = result[i - 1];
            vector<int> row(i + 1, 0);
            // 边界为 1
            row[0] = 1;
            row[i] = 1;
            for (int j = 1; j < i; j++) {
                row[j] = last[j - 1] + last[j];
            }
            result.emplace_back(row);
        }
        return result;
    }
};
// @lc code=end
