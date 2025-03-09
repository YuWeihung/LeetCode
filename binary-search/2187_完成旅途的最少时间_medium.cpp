/*
 * @lc app=leetcode.cn id=2187 lang=cpp
 *
 * [2187] 完成旅途的最少时间
 */
#include <algorithm>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
    bool check(vector<int> &time, int totalTrips, long long ans) {
        long long sum = 0;
        for (int t : time) {
            long long cur = ans / t;
            sum += cur;
        }
        if (sum >= totalTrips) {
            return true;
        } else {
            return false;
        }
    }

    long long minimumTime(vector<int> &time, int totalTrips) {
        int minn = *min_element(time.begin(), time.end());
        long long left = minn;
        long long right = (long long)totalTrips * minn - 1;
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            if (check(time, totalTrips, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
// @lc code=end
