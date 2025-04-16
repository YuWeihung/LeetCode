/*
 * @lc app=leetcode.cn id=2537 lang=cpp
 *
 * [2537] 统计好子数组的数目
 */
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    long long countGood(vector<int> &nums, int k) {
        int n = nums.size();
        unordered_map<int, int> cnt;
        long long ans = 0;
        int pairs = 0, left = 0;
        for (int right = 0; right < n; right++) {
            pairs += cnt[nums[right]];
            cnt[nums[right]]++;
            while (pairs >= k) {
                cnt[nums[left]]--;
                pairs -= cnt[nums[left]];
                left++;
            }
            ans += left;
        }
        return ans;
    }
};
// @lc code=end
