/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */
#include <deque>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int> &nums, int k) {
        int n = nums.size(), ans = n + 1;
        vector<long long> s(n + 1);
        for (int i = 0; i < n; i++) {
            s[i + 1] = s[i] + nums[i];
        }
        deque<int> q;
        for (int i = 0; i <= n; i++) {
            long long cur_s = s[i];
            while (!q.empty() && cur_s - s[q.front()] >= k) {
                ans = min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && s[q.back()] >= cur_s) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return ans > n ? -1 : ans;
    }
};
// @lc code=end
