/*
 * @lc app=leetcode.cn id=1901 lang=cpp
 *
 * [1901] 寻找峰值 II
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int indexOfMax(vector<int> &nums) {
        auto maxit = max_element(nums.begin(), nums.end());
        int res = maxit - nums.begin();
        return res;
    }

    vector<int> findPeakGrid(vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        int low = 0, high = m - 2;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int maxi = indexOfMax(mat[mid]);
            if (mat[mid][maxi] > mat[mid + 1][maxi]) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return {low, indexOfMax(mat[low])};
    }
};
// @lc code=end
