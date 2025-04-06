/*
 * @lc app=leetcode.cn id=2786 lang=cpp
 *
 * [2786] 访问数组中的位置使分数最大
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    long long maxScore(vector<int> &nums, int x) {
        int n = nums.size();
        vector f(n + 1, vector<long long>(2));
        for (int i = n - 1; i >= 0; i--) {
            int v = nums[i];
            int r = v % 2;
            // 对于奇偶性相同，必须选
            f[i][r] = f[i + 1][r] + v;
            // 奇偶性不同，选或不选
            f[i][r ^ 1] = max(f[i + 1][r ^ 1], f[i + 1][r] - x + v);
        }
        return f[0][nums[0] % 2];
    }
};
// @lc code=end
