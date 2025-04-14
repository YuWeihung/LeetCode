/*
 * @lc app=leetcode.cn id=1696 lang=cpp
 *
 * [1696] 跳跃游戏 VI
 */
#include <algorithm>
#include <climits>
#include <deque>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxResult(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> f(n);
        f[0] = nums[0];
        deque<int> q = {0};
        for (int i = 1; i < n; i++) {
            // 1. 出
            if (q.front() < i - k) {
                q.pop_front();
            }
            // 2. 转移
            f[i] = f[q.front()] + nums[i];
            // 3. 入
            while (!q.empty() && f[i] >= f[q.back()]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        return f[n - 1];
    }
};
// @lc code=end
