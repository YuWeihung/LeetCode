/*
 * @lc app=leetcode.cn id=48 lang=cpp
 *
 * [48] 旋转图像
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    // 从外到内旋转，depth 是第几层，length 是当前层有多少个元素
    void rotate(vector<vector<int>> &matrix) {
        int n = matrix.size();
        int depth = 0;
        int length = n;
        while (length > 1) {
            for (int i = 0; i < length - 1; i++) {
                int t = matrix[depth][depth + i];
                // 以三阶矩阵为例 a[0][0] = a[2][0]
                matrix[depth][depth + i] = matrix[n - 1 - depth - i][depth];
                // a[2][0] = a[2][2]
                matrix[n - 1 - depth - i][depth] = matrix[n - 1 - depth][n - 1 - depth - i];
                // a[2][2] = a[0][2]
                matrix[n - 1 - depth][n - 1 - depth - i] = matrix[depth + i][n - 1 - depth];
                // a[0][2] = a[0][0]
                matrix[depth + i][n - 1 - depth] = t;
            }
            length -= 2;
            depth++;
        }
    }
};
// @lc code=end
