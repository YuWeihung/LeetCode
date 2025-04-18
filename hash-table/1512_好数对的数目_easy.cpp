/*
 * @lc app=leetcode.cn id=1512 lang=cpp
 *
 * [1512] 好数对的数目
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int numIdenticalPairs(vector<int> &nums) {
        unordered_map<int, int> cnt;
        int n = nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += cnt[nums[i]];
            cnt[nums[i]]++;
        }
        return ans;
    }
};
// @lc code=end
