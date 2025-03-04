/*
 * @lc app=leetcode.cn id=2300 lang=cpp
 *
 * [2300] 咒语和药水的成功对数
 */
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    int lower_bound(vector<int> &nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    vector<int> successfulPairs(vector<int> &spells,
                                vector<int> &potions,
                                long long success) {
        sort(potions.begin(), potions.end());
        for (int i = 0; i < spells.size(); i++) {
            long long target = (success - 1) / spells[i] + 1;
            if (target <= potions.back()) {
                int start = lower_bound(potions, target);
                int n = potions.size() - start;
                spells[i] = n;
            } else {
                spells[i] = 0;
            }
        }
        return spells;
    }
};
// @lc code=end
