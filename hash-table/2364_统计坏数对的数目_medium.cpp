/*
 * @lc app=leetcode.cn id=2364 lang=cpp
 *
 * [2364] 统计坏数对的数目
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    long long countBadPairs(vector<int> &nums) {
        int n = nums.size();
        long long ans = 1LL * n * (n - 1) / 2;
        unordered_map<int, int> cnt;
        for (int i = 0; i < n; i++) {
            ans -= cnt[nums[i] - i];
            cnt[nums[i] - i]++;
        }
        return ans;
    }
};
// @lc code=end
