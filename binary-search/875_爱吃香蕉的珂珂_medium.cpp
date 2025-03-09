/*
 * @lc app=leetcode.cn id=875 lang=cpp
 *
 * [875] 爱吃香蕉的珂珂
 */
#include <algorithm>
#include <vector>

using namespace std;

// left - 1 恒为 false 初始为 0
// right + 1 恒为 true 初始为 maxn - 1

// @lc code=start
class Solution {
public:
    int minEatingSpeed(vector<int> &piles, int h) {
        int left = 1;
        int maxn = 0;
        int right = *max_element(piles.begin(), piles.end()) - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (check(piles, mid, h)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

    bool check(const vector<int> &piles, int speed, int target) {
        long time = 0;
        for (int pile : piles) {
            int curTime = (pile + speed - 1) / speed;
            time += curTime;
            if (time > target) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
