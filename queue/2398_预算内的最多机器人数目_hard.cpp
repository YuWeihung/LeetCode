/*
 * @lc app=leetcode.cn id=2398 lang=cpp
 *
 * [2398] 预算内的最多机器人数目
 */
#include <deque>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int maximumRobots(vector<int> &chargeTimes,
                      vector<int> &runningCosts,
                      long long budget) {
        int ans = 0, left = 0;
        long long sum = 0;
        deque<int> q;
        for (int right = 0; right < chargeTimes.size(); right++) {
            while (!q.empty() &&
                   chargeTimes[right] >= chargeTimes[q.back()]) {
                q.pop_back();
            }
            q.push_back(right);
            sum += runningCosts[right];

            while (!q.empty() &&
                   chargeTimes[q.front()] + (right - left + 1) * sum >
                       budget) {
                if (q.front() == left) {
                    q.pop_front();
                }
                sum -= runningCosts[left];
                left++;
            }
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};
// @lc code=end
