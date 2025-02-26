/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */
#include <vector>

using namespace std;

// Boyer-Moore 投票算法

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int candidate = -1;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) {
                candidate = nums[i];
            }
            if (nums[i] == candidate) {
                count--;
            } else {
                count++;
            }
        }
        return candidate;
    }
};
// @lc code=end
