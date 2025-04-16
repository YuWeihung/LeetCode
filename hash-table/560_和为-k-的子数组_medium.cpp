/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int> &nums, int k) {
        int n = nums.size();
        int ans = 0;
        vector<int> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }
        unordered_map<int, int> cnt;
        for (int sj : s) {
            ans += cnt[sj - k];
            cnt[sj]++;
        }
        return ans;
    }
};
// @lc code=end
