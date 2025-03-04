/*
 * @lc app=leetcode.cn id=275 lang=cpp
 *
 * [275] H 指数 II
 */
#include <iostream>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
    int hIndex(vector<int> &citations) {
        int n = citations.size(), left = 1, right = n;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (citations[n - mid] >= mid) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return right;
    }
};
// @lc code=end
